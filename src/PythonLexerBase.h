#pragma once

#include "antlr4-runtime.h"

#include <memory>
#include <queue>
#include <string>
#include <vector>

// Base class for the generated PythonRustLexer. It post-processes the raw token
// stream to emit Python-style INDENT / DEDENT tokens and to drop NEWLINEs that
// occur inside (), [] or {} (implicit line joining).
class PythonLexerBase : public antlr4::Lexer {
public:
    explicit PythonLexerBase(antlr4::CharStream *input);

    std::unique_ptr<antlr4::Token> nextToken() override;
    void reset() override;

private:
    std::queue<std::unique_ptr<antlr4::Token>> _pending;
    std::vector<int> _indents;
    int _opened = 0;
    size_t _lastType = antlr4::Token::INVALID_TYPE;

    bool _resolved = false;
    size_t T_NEWLINE = 0, T_INDENT = 0, T_DEDENT = 0;
    size_t T_LPAREN = 0, T_RPAREN = 0;
    size_t T_LBRACK = 0, T_RBRACK = 0;
    size_t T_LBRACE = 0, T_RBRACE = 0;

    void resolveTypes();
    int countIndent(const std::string &text) const;
    // Pass line=0 for a positionless token, otherwise we attach line/col so
    // parser-side errors involving synthetic INDENT/DEDENT/NEWLINE tokens
    // point at the offending line.
    std::unique_ptr<antlr4::Token> makeToken(size_t type, const std::string &text,
                                             size_t line = 0, size_t col = 0);
    bool isOpen(size_t t) const { return t == T_LPAREN || t == T_LBRACK || t == T_LBRACE; }
    bool isClose(size_t t) const { return t == T_RPAREN || t == T_RBRACK || t == T_RBRACE; }
};
