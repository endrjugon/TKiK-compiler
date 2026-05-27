
#include "PythonLexerBase.h"


// Generated from grammar/PythonRustLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  PythonRustLexer : public PythonLexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, DEF = 3, RETURN = 4, IF = 5, ELIF = 6, ELSE = 7, 
    WHILE = 8, FOR = 9, IN = 10, BREAK = 11, CONTINUE = 12, PASS = 13, TRY = 14, 
    EXCEPT = 15, FINALLY = 16, RAISE = 17, CLASS = 18, IMPORT = 19, FROM = 20, 
    AS = 21, TRUE = 22, FALSE = 23, NONE = 24, AND = 25, OR = 26, NOT = 27, 
    ARROW = 28, PLUS = 29, MINUS = 30, STAR = 31, DIV = 32, MOD = 33, EQ = 34, 
    NEQ = 35, LE = 36, GE = 37, ASSIGN = 38, LT = 39, GT = 40, LPAREN = 41, 
    RPAREN = 42, LBRACK = 43, RBRACK = 44, LBRACE = 45, RBRACE = 46, COLON = 47, 
    COMMA = 48, DOT = 49, FLOAT = 50, INT = 51, STRING = 52, ID = 53, NEWLINE = 54, 
    LINE_JOIN = 55, WS = 56, COMMENT = 57
  };

  explicit PythonRustLexer(antlr4::CharStream *input);

  ~PythonRustLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

