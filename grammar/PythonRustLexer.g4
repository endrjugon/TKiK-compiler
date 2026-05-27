lexer grammar PythonRustLexer;

// The indentation logic (INDENT / DEDENT generation, implicit line joining
// inside brackets) lives in a hand-written C++ base class.
options { superClass = PythonLexerBase; }

@header {
#include "PythonLexerBase.h"
}

// Virtual tokens produced by PythonLexerBase, not by any lexer rule.
tokens { INDENT, DEDENT }

// --- KEYWORDS (must precede ID so they win equal-length matches) ---
DEF      : 'def';
RETURN   : 'return';
IF       : 'if';
ELIF     : 'elif';
ELSE     : 'else';
WHILE    : 'while';
FOR      : 'for';
IN       : 'in';
BREAK    : 'break';
CONTINUE : 'continue';
PASS     : 'pass';
TRY      : 'try';
EXCEPT   : 'except';
FINALLY  : 'finally';
RAISE    : 'raise';
CLASS    : 'class';
IMPORT   : 'import';
FROM     : 'from';
AS       : 'as';
TRUE     : 'True';
FALSE    : 'False';
NONE     : 'None';
AND      : 'and';
OR       : 'or';
NOT      : 'not';

// --- OPERATORS ---
ARROW  : '->';
PLUS   : '+';
MINUS  : '-';
STAR   : '*';
DIV    : '/';
MOD    : '%';
EQ     : '==';
NEQ    : '!=';
LE     : '<=';
GE     : '>=';
ASSIGN : '=';
LT     : '<';
GT     : '>';

// --- PUNCTUATION ---
LPAREN : '(';
RPAREN : ')';
LBRACK : '[';
RBRACK : ']';
LBRACE : '{';
RBRACE : '}';
COLON  : ':';
COMMA  : ',';
DOT    : '.';

// --- LITERALS AND IDENTIFIERS ---
FLOAT  : DIGIT+ '.' DIGIT* | '.' DIGIT+ ;
INT    : DIGIT+ ;
STRING : '"""' .*? '"""'
       | '\'\'\'' .*? '\'\'\''
       | '"'  ( '\\' . | ~["\\\r\n] )* '"'
       | '\'' ( '\\' . | ~['\\\r\n] )* '\'' ;
ID     : [a-zA-Z_] [a-zA-Z0-9_]* ;

// --- WHITESPACE AND COMMENTS ---
// NEWLINE also captures the indentation of the following line; the base class
// turns indentation changes into INDENT / DEDENT tokens.
NEWLINE   : ( '\r'? '\n' | '\r' | '\f' ) [ \t]* ;
LINE_JOIN : '\\' '\r'? '\n' -> skip ;
WS        : [ \t]+ -> skip ;
COMMENT   : '#' ~[\r\n]* -> skip ;

fragment DIGIT : [0-9] ;
