# Konwerter Python do Rust

## Autorzy:

- **Andrzej Gondek**,
- **Krzysztof Gniewek**

## Dane kontaktowe :

- Andrzej Gondek - agondek@student.agh.edu.pl
- Krzysztof Gniewek - gniewek@student.agh.edu.pl

## Założenia programu

Celem projektu jest stworzenie narzędzia które tłumaczy określony fragment kodu napisany w języku Python na bezpieczny, statycznie typowany i wydajny kod w języku Rust.

### Rodzaj translatora - Konwerter

Program przyjmuje na wejściu plik z kodem źródłowym Pythona (`.py`), obsługujący podstawowe struktury (pętle, instrukcje warunkowe), proste operacje arytmetyczne i definicje funkcji z adnotacjami typów.

### Wynik działania programu to plik w języku Rust (`.rs`), który realizuje tę samą logikę.

- Wejście: Skrypt `kalkulator.py` (Python)
- Wyjście: Plik `kalkulator.rs` (Rust), gotowy do skompilowania narzędziem `rustc`.

### Planowany język implementacji

- **Python 3.13**

### Sposób realizacji skanera/parsera

Użycie zewnętrznego generatora skanerów i parserów :  
**ANTLR4**

### Opis tokenów

| Nazwa | Opis | Regex / Wzorzec | Przykład |
| :--- | :--- | :--- | :--- |
| **Białe Znaki i Wcięcia** | | | |
| `NEWLINE` | Znak nowej linii | `('\r'? '\n')+` | `\n`, `\r\n` |
| `INDENT` | Zwiększenie wcięcia | `'<INDENT>'` | *(wcięcie bloku)* |
| `DEDENT` | Zmniejszenie wcięcia | `'<DEDENT>'` | *(powrót wcięcia)* |
| `WS` | Ignorowane spacje/tabulatory | `[ \t]+ -> skip` | ` `, `\t` |
| **Słowa Kluczowe** | | | |
| `DEF` | Definicja funkcji | `'def'` | `def` |
| `RETURN` | Zwrot wartości | `'return'` | `return` |
| `IF` | Instrukcja warunkowa | `'if'` | `if` |
| `ELIF` | Alternatywa warunkowa | `'elif'` | `elif` |
| `ELSE` | Alternatywa | `'else'` | `else` |
| `WHILE` | Pętla warunkowa | `'while'` | `while` |
| `FOR` | Pętla iteracyjna | `'for'` | `for` |
| `IN` | Operator inkluzji | `'in'` | `in` |
| `BREAK` | Przerwanie pętli | `'break'` | `break` |
| `CONTINUE` | Kontynuacja pętli | `'continue'` | `continue` |
| `PASS` | Instrukcja pusta | `'pass'` | `pass` |
| `TRY` | Blok obsługi błędów | `'try'` | `try` |
| `EXCEPT` | Przechwycenie błędu | `'except'` | `except` |
| `FINALLY` | Blok końcowy dla try | `'finally'` | `finally` |
| `RAISE` | Rzucenie wyjątku | `'raise'` | `raise` |
| `CLASS` | Definicja klasy | `'class'` | `class` |
| `IMPORT` | Import modułu | `'import'` | `import` |
| `FROM` | Częściowy import | `'from'` | `from` |
| **Typy Bazowe i Logika** | | | |
| `TRUE` | Prawda logiczna | `'True'` | `True` |
| `FALSE` | Fałsz logiczny | `'False'` | `False` |
| `NONE` | Wartość pusta (Null) | `'None'` | `None` |
| `AND` | Koniunkcja logiczna | `'and'` | `and` |
| `OR` | Alternatywa logiczna | `'or'` | `or` |
| `NOT` | Negacja logiczna | `'not'` | `not` |
| **Operatory** | | | |
| `PLUS` | Dodawanie | `'+'` | `+` |
| `MINUS` | Odejmowanie | `'-'` | `-` |
| `STAR` | Mnożenie | `'*'` | `*` |
| `DIV` | Dzielenie | `'/'` | `/` |
| `MOD` | Reszta z dzielenia (Modulo) | `'%'` | `%` |
| `ASSIGN` | Przypisanie | `'='` | `=` |
| `EQ` | Równość | `'=='` | `==` |
| `NEQ` | Nierówność | `'!='` | `!=` |
| `LT` | Mniejsze niż | `'<'` | `<` |
| `GT` | Większe niż | `'>'` | `>` |
| `LE` | Mniejsze lub równe | `'<='` | `<=` |
| `GE` | Większe lub równe | `'>='` | `>=` |
| **Znaki Przestankowe** | | | |
| `LPAREN` | Lewy nawias okrągły | `'('` | `(` |
| `RPAREN` | Prawy nawias okrągły | `')'` | `)` |
| `LBRACK` | Lewy nawias kwadratowy | `'['` | `[` |
| `RBRACK` | Prawy nawias kwadratowy | `']'` | `]` |
| `LBRACE` | Lewy nawias klamrowy | `'{'` | `{` |
| `RBRACE` | Prawy nawias klamrowy | `'}'` | `}` |
| `COLON` | Dwukropek | `':'` | `:` |
| `COMMA` | Przecinek | `','` | `,` |
| `DOT` | Kropka / Dostęp do pól | `'.'` | `.` |
| **Literały i Identyfikatory** | | | |
| `ID` | Identyfikator (zmienna/funkcja) | `[a-zA-Z_][a-zA-Z0-9_]*` | `my_var`, `_temp` |
| `INT` | Liczba całkowita | `[0-9]+` | `42`, `0` |
| `FLOAT` | Liczba zmiennoprzecinkowa | `[0-9]+ '.' [0-9]+` | `3.14`, `0.5` |
| `STRING` | Ciąg znaków | `'"' ~["]* '"' \| '\'' ~[']* '\''` | `"text"`, `'text'` |
| **Inne** | | | |
| `COMMENT` | Komentarz (ignorowany) | `'#' ~[\r\n]* -> skip` | `# to jest uwaga` |

### Gramatyka 

```
MiniPythonParser ::= prog

prog ::= (statement)* EOF

statement ::= simple_stmt NEWLINE | compound_stmt

suite ::= simple_stmt NEWLINE | NEWLINE INDENT statement+ DEDENT

compound_stmt ::= if_stmt | while_stmt | for_stmt | try_stmt | funcdef | classdef

if_stmt ::= IF expr COLON suite (ELIF expr COLON suite)* (ELSE COLON suite)?

while_stmt ::= WHILE expr COLON suite

for_stmt ::= FOR ID IN expr COLON suite

try_stmt ::= TRY COLON suite (EXCEPT ID? COLON suite)+ (FINALLY COLON suite)?

funcdef ::= DEF ID LPAREN parameters? RPAREN COLON suite

classdef ::= CLASS ID (LPAREN ID RPAREN)? COLON suite

simple_stmt ::= assign_stmt | expr_stmt | return_stmt | import_stmt | raise_stmt | pass_stmt | flow_stmt

assign_stmt ::= expr ASSIGN expr

expr_stmt ::= expr

return_stmt ::= RETURN expr?

import_stmt ::= IMPORT ID | FROM ID IMPORT ID

raise_stmt ::= RAISE expr

pass_stmt ::= PASS

flow_stmt ::= BREAK | CONTINUE

parameters ::= ID (COMMA ID)*

arguments ::= expr (COMMA expr)*

expr ::= MulDivExpr | AddSubExpr | CompExpr | NotExpr | AndExpr | OrExpr | CallExpr | MemberAccessExpr | IndexExpr | AtomExpr

MulDivExpr ::= expr (STAR | DIV | MOD) expr

AddSubExpr ::= expr (PLUS | MINUS) expr

CompExpr ::= expr (EQ | NEQ | LT | GT | LE | GE) expr

NotExpr ::= NOT expr

AndExpr ::= expr AND expr

OrExpr ::= expr OR expr

CallExpr ::= atom LPAREN arguments? RPAREN

MemberAccessExpr ::= atom DOT ID

IndexExpr ::= atom LBRACK expr RBRACK

AtomExpr ::= atom

atom ::= INT | FLOAT | STRING | TRUE | FALSE | NONE | ID | list_maker | dict_maker | set_maker | LPAREN expr RPAREN

list_maker ::= LBRACK (expr (comp_clause | (COMMA expr)*))? RBRACK

set_maker ::= LBRACE expr (comp_clause | (COMMA expr)*) RBRACE

dict_maker ::= LBRACE (dict_kv (comp_clause | (COMMA dict_kv)*))? RBRACE

dict_kv ::= expr COLON expr

comp_clause ::= FOR ID IN expr (IF expr)?