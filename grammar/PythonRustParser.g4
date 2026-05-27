parser grammar PythonRustParser;

options { tokenVocab = PythonRustLexer; }

// --- TOP LEVEL ---
program       : (NEWLINE | stmt)* EOF ;

stmt          : simple_stmt
              | compound_stmt ;

simple_stmt   : small_stmt NEWLINE ;

small_stmt    : expr_stmt
              | return_stmt
              | import_stmt
              | raise_stmt
              | pass_stmt
              | flow_stmt ;

// --- SIMPLE STATEMENTS ---
// Covers expression statements, plain/chained assignment, tuple unpacking
// (a, b = ...), and annotated assignment (x: int = ...).
expr_stmt     : testlist ( annassign
                         | (ASSIGN testlist)*
                         ) ;
annassign     : COLON type (ASSIGN testlist)? ;

return_stmt   : RETURN testlist? ;
import_stmt   : IMPORT dotted_name (AS ID)?
              | FROM dotted_name IMPORT import_list ;
import_list   : STAR
              | ID (AS ID)? (COMMA ID (AS ID)?)* ;
dotted_name   : ID (DOT ID)* ;
raise_stmt    : RAISE (expr (FROM expr)?)? ;
pass_stmt     : PASS ;
flow_stmt     : BREAK | CONTINUE ;

// --- COMPOUND STATEMENTS ---
compound_stmt : if_stmt | while_stmt | for_stmt | try_stmt | funcdef | classdef ;

if_stmt       : IF expr COLON suite (ELIF expr COLON suite)* (ELSE COLON suite)? ;
while_stmt    : WHILE expr COLON suite (ELSE COLON suite)? ;
for_stmt      : FOR target_list IN testlist COLON suite (ELSE COLON suite)? ;
try_stmt      : TRY COLON suite
                ( (except_clause COLON suite)+ (ELSE COLON suite)? (FINALLY COLON suite)?
                | FINALLY COLON suite
                ) ;
except_clause : EXCEPT (expr (AS ID)?)? ;

funcdef       : DEF ID LPAREN parameters? RPAREN (ARROW type)? COLON suite ;
classdef      : CLASS ID (LPAREN arglist? RPAREN)? COLON suite ;

suite         : simple_stmt
              | NEWLINE INDENT stmt+ DEDENT ;

// --- PARAMETERS / ARGUMENTS / TARGETS ---
parameters    : param (COMMA param)* COMMA? ;
param         : ID (COLON type)? (ASSIGN expr)? ;

arglist       : argument (COMMA argument)* COMMA? ;
argument      : ID ASSIGN expr   # KwArg
              | expr             # PosArg ;

// for-loop / comprehension targets (names, possibly nested tuples for unpacking)
target_list   : target (COMMA target)* COMMA? ;
target        : ID
              | LPAREN target_list RPAREN
              | LBRACK target_list RBRACK ;

// Comma-separated expression list. Becomes a tuple when it holds more than one
// element or carries a trailing comma; otherwise it is a single expression.
testlist      : expr (COMMA expr)* COMMA? ;

// Type annotation, e.g. int, float, str, list[int], tuple[int, str], dict[str, int].
type          : ID (LBRACK type (COMMA type)* RBRACK)?
              | NONE ;

// --- EXPRESSIONS (precedence: highest alternative first) ---
expr          : expr LPAREN arglist? RPAREN              # CallExpr
              | expr LBRACK subscript RBRACK             # IndexExpr
              | expr DOT ID                              # MemberExpr
              | (PLUS | MINUS) expr                      # UnaryExpr
              | expr (STAR | DIV | MOD) expr             # MulDivExpr
              | expr (PLUS | MINUS) expr                 # AddSubExpr
              | expr (LT | GT | LE | GE | EQ | NEQ) expr # CompExpr
              | NOT expr                                 # NotExpr
              | expr AND expr                            # AndExpr
              | expr OR expr                             # OrExpr
              | atom                                     # AtomExpr ;

subscript     : slice | expr ;
slice         : expr? COLON expr? (COLON expr?)? ;

// --- ATOMS (literals, identifiers, collections, tuples) ---
atom          : INT                                      # IntAtom
              | FLOAT                                    # FloatAtom
              | STRING                                   # StringAtom
              | TRUE                                     # TrueAtom
              | FALSE                                    # FalseAtom
              | NONE                                     # NoneAtom
              | ID                                       # IdAtom
              | list_maker                               # ListAtom
              | set_or_dict                              # SetDictAtom
              | LPAREN testlist? RPAREN                  # GroupOrTupleAtom ;

// --- COLLECTIONS AND COMPREHENSIONS ---
list_maker    : LBRACK ( expr comp_clause                // list comprehension
                       | expr (COMMA expr)* COMMA?        // list literal
                       )? RBRACK ;

set_or_dict   : LBRACE ( dict_kv comp_clause             // dict comprehension
                       | dict_kv (COMMA dict_kv)* COMMA?  // dict literal
                       | expr comp_clause                // set comprehension
                       | expr (COMMA expr)* COMMA?        // set literal
                       )? RBRACE ;

dict_kv       : expr COLON expr ;
comp_clause   : FOR target_list IN expr (IF expr)? comp_clause? ;
