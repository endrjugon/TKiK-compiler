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

std::unique_ptr<antlr4::Token> PythonLexerBase::makeToken(size_t type, const std::string &text) {
    return _factory->create(type, text);
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
                _pending.push(makeToken(T_NEWLINE, "\n"));
            }

            if (lookType == Token::EOF) {
                while (!_indents.empty()) {
                    _pending.push(makeToken(T_DEDENT, ""));
                    _indents.pop_back();
                }
                _pending.push(std::move(look));
                _lastType = Token::EOF;
            } else {
                int prev = _indents.empty() ? 0 : _indents.back();
                if (indent > prev) {
                    _indents.push_back(indent);
                    _pending.push(makeToken(T_INDENT, ""));
                } else {
                    while (!_indents.empty() && _indents.back() > indent) {
                        _pending.push(makeToken(T_DEDENT, ""));
                        _indents.pop_back();
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
                _pending.push(makeToken(T_NEWLINE, "\n"));
            }
            while (!_indents.empty()) {
                _pending.push(makeToken(T_DEDENT, ""));
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
