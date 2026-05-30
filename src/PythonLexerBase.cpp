#include "PythonLexerBase.h"

using antlr4::Token;

PythonLexerBase::PythonLexerBase(antlr4::CharStream *input) : antlr4::Lexer(input) {}

void PythonLexerBase::reset() {
    std::queue<std::unique_ptr<antlr4::Token>> empty;
    std::swap(_pending, empty);
    _indents.clear();
    _opened = 0;
    _lastType = Token::INVALID_TYPE;
    antlr4::Lexer::reset();
}

void PythonLexerBase::resolveTypes() {
    const antlr4::dfa::Vocabulary &vocab = getVocabulary();
    size_t maxT = vocab.getMaxTokenType();
    for (size_t i = 0; i <= maxT; i++) {
        std::string_view name = vocab.getSymbolicName(i);
        if (name == "NEWLINE") T_NEWLINE = i;
        else if (name == "INDENT") T_INDENT = i;
        else if (name == "DEDENT") T_DEDENT = i;
        else if (name == "LPAREN") T_LPAREN = i;
        else if (name == "RPAREN") T_RPAREN = i;
        else if (name == "LBRACK") T_LBRACK = i;
        else if (name == "RBRACK") T_RBRACK = i;
        else if (name == "LBRACE") T_LBRACE = i;
        else if (name == "RBRACE") T_RBRACE = i;
    }
    _resolved = true;
}

int PythonLexerBase::countIndent(const std::string &text) const {
    int col = 0;
    for (char c : text) {
        if (c == '\t') col += 8 - (col % 8);
        else if (c == ' ') col += 1;
        // newline characters carry no indentation
    }
    return col;
}

std::unique_ptr<antlr4::Token> PythonLexerBase::makeToken(size_t type, const std::string &text,
                                                          size_t line, size_t col) {
    if (line == 0) return _factory->create(type, text);
    return _factory->create({this, _input}, type, text,
                            antlr4::Token::DEFAULT_CHANNEL, 0, 0, line, col);
}

std::unique_ptr<antlr4::Token> PythonLexerBase::nextToken() {
    if (!_resolved) resolveTypes();

    while (_pending.empty()) {
        std::unique_ptr<antlr4::Token> t = antlr4::Lexer::nextToken();
        size_t type = t->getType();

        if (isOpen(type)) {
            _opened++;
            _lastType = type;
            _pending.push(std::move(t));
            break;
        }
        if (isClose(type)) {
            if (_opened > 0) _opened--;
            _lastType = type;
            _pending.push(std::move(t));
            break;
        }

        if (type == T_NEWLINE) {
            if (_opened > 0) {
                // Implicit line continuation inside brackets: discard the newline.
                continue;
            }
            // Collapse a run of NEWLINEs (blank / comment-only lines). The
            // indentation that matters is the one right before the next real line.
            std::unique_ptr<antlr4::Token> nl = std::move(t);
            std::unique_ptr<antlr4::Token> look = antlr4::Lexer::nextToken();
            while (look->getType() == T_NEWLINE) {
                nl = std::move(look);
                look = antlr4::Lexer::nextToken();
            }

            int indent = countIndent(nl->getText());
            size_t lookType = look->getType();

            // Emit the logical NEWLINE (suppressed only at the very start of input).
            if (_lastType != Token::INVALID_TYPE) {
                _pending.push(makeToken(T_NEWLINE, "\n", look->getLine(), 0));
            }

            if (lookType == Token::EOF) {
                while (!_indents.empty()) {
                    _pending.push(makeToken(T_DEDENT, "<DEDENT>", look->getLine(), 0));
                    _indents.pop_back();
                }
                _pending.push(std::move(look));
                _lastType = Token::EOF;
            } else {
                // --- wrong-indent detection ---
                // Mixed tabs and spaces in this line's indentation.
                bool hasTab = false, hasSpace = false;
                for (char ch : nl->getText()) {
                    if (ch == '\t') hasTab = true;
                    else if (ch == ' ') hasSpace = true;
                }
                if (hasTab && hasSpace) {
                    getErrorListenerDispatch().syntaxError(
                        this, nullptr, look->getLine(), 0,
                        "inconsistent use of tabs and spaces in indentation",
                        nullptr);
                }

                int prev = _indents.empty() ? 0 : _indents.back();
                if (indent > prev) {
                    _indents.push_back(indent);
                    _pending.push(makeToken(T_INDENT, "<INDENT>", look->getLine(), 0));
                } else {
                    while (!_indents.empty() && _indents.back() > indent) {
                        _pending.push(makeToken(T_DEDENT, "<DEDENT>", look->getLine(), 0));
                        _indents.pop_back();
                    }
                    // After popping, the new level must match an outer one
                    // (otherwise we have something like dedent to 6 when the
                    // outer levels were 0 and 4 - Python rejects this).
                    int after = _indents.empty() ? 0 : _indents.back();
                    if (after != indent) {
                        getErrorListenerDispatch().syntaxError(
                            this, nullptr, look->getLine(), 0,
                            "unindent does not match any outer indentation level",
                            nullptr);
                    }
                }
                if (isOpen(lookType)) _opened++;
                else if (isClose(lookType) && _opened > 0) _opened--;
                _lastType = lookType;
                _pending.push(std::move(look));
            }
            break;
        }

        if (type == Token::EOF) {
            // File that does not end in a newline: synthesize one, then close blocks.
            if (_lastType != Token::INVALID_TYPE && _lastType != T_NEWLINE) {
                _pending.push(makeToken(T_NEWLINE, "\n", t->getLine(), 0));
            }
            while (!_indents.empty()) {
                _pending.push(makeToken(T_DEDENT, "<DEDENT>", t->getLine(), 0));
                _indents.pop_back();
            }
            _pending.push(std::move(t));
            _lastType = Token::EOF;
            break;
        }

        // Ordinary token.
        _lastType = type;
        _pending.push(std::move(t));
        break;
    }

    std::unique_ptr<antlr4::Token> out = std::move(_pending.front());
    _pending.pop();
    return out;
}
