# Konwerter Python → Rust

## Dane studentów

- **Andrzej Gondek**
- **Krzysztof Gniewek**

## Dane kontaktowe

- Andrzej Gondek – agondek@student.agh.edu.pl
- Krzysztof Gniewek – gniewek@student.agh.edu.pl

## Założenia programu

### Ogólne cele programu

Celem projektu jest stworzenie narzędzia, które tłumaczy określony podzbiór kodu
napisanego w języku **Python** na bezpieczny, statycznie typowany i wydajny kod
w języku **Rust**. Obsługiwane są funkcje z adnotacjami typów, instrukcje
sterujące (warunki, pętle), operacje arytmetyczne, logiczne i porównania,
kolekcje (listy, słowniki, zbiory), wyrażenia listowe (*comprehensions*), klasy
oraz **krotki (tuple)** – będące przedmiotem rozszerzenia gramatyki w tym
projekcie.

### Rodzaj translatora

**Kompilator** (konwerter typu *source-to-source*). Program nie wykonuje kodu –
dokonuje pełnej analizy leksykalnej i składniowej pliku wejściowego, buduje
drzewo rozbioru, a następnie generuje równoważny kod wynikowy.

### Planowany wynik działania programu

Kompilator (konwerter) języka **Python** do kodu **Rust**:

- **Wejście:** plik `*.py` (Python), np. `kalkulator.py`,
- **Wyjście:** plik `*.rs` (Rust), np. `kalkulator.rs`, gotowy do skompilowania
  narzędziem `rustc`.

### Planowany język implementacji

- **C++ (standard C++17).**

Skompilowany konwerter to pojedynczy, samodzielny plik wykonywalny
(`pyrust.exe`), bez zależności od bibliotek DLL.

### Sposób realizacji skanera/parsera

Użycie zewnętrznego generatora skanerów i parserów: **ANTLR 4** (cel/target
**C++**). Gramatyka jest podzielona na gramatykę leksera i parsera w katalogu
`grammar/`. Wcięcia bloków w stylu Pythona (tokeny `INDENT`/`DEDENT`) oraz
domyślne łączenie linii wewnątrz nawiasów `()`, `[]`, `{}` realizuje ręcznie
napisana klasa bazowa leksera `PythonLexerBase` (plik `src/PythonLexerBase.cpp`),
wskazana w gramatyce poprzez opcję `superClass`.

## Opis tokenów

Tokeny zdefiniowane w gramatyce leksera (`grammar/PythonRustLexer.g4`).

| Nazwa | Opis | Wzorzec (notacja ANTLR) | Przykład |
| :--- | :--- | :--- | :--- |
| **Białe znaki i wcięcia** | | | |
| `NEWLINE` | Koniec linii + wcięcie następnej | `('\r'? '\n' \| '\r' \| '\f') [ \t]*` | `\n` |
| `INDENT` | Zwiększenie wcięcia (token wirtualny) | *generowany przez `PythonLexerBase`* | *(wejście do bloku)* |
| `DEDENT` | Zmniejszenie wcięcia (token wirtualny) | *generowany przez `PythonLexerBase`* | *(wyjście z bloku)* |
| `LINE_JOIN` | Jawne łączenie linii (ignorowane) | `'\\' '\r'? '\n' -> skip` | `\<enter>` |
| `WS` | Spacje/tabulatory (ignorowane) | `[ \t]+ -> skip` | ` `, `\t` |
| `COMMENT` | Komentarz (ignorowany) | `'#' ~[\r\n]* -> skip` | `# uwaga` |
| **Słowa kluczowe** | | | |
| `DEF` | Definicja funkcji | `'def'` | `def` |
| `RETURN` | Zwrot wartości | `'return'` | `return` |
| `IF` `ELIF` `ELSE` | Instrukcje warunkowe | `'if'` `'elif'` `'else'` | `if` |
| `WHILE` | Pętla warunkowa | `'while'` | `while` |
| `FOR` `IN` | Pętla iteracyjna | `'for'` `'in'` | `for` |
| `BREAK` `CONTINUE` | Sterowanie pętlą | `'break'` `'continue'` | `break` |
| `PASS` | Instrukcja pusta | `'pass'` | `pass` |
| `TRY` `EXCEPT` `FINALLY` | Obsługa błędów | `'try'` `'except'` `'finally'` | `try` |
| `RAISE` | Rzucenie wyjątku | `'raise'` | `raise` |
| `CLASS` | Definicja klasy | `'class'` | `class` |
| `IMPORT` `FROM` `AS` | Importy | `'import'` `'from'` `'as'` | `import` |
| `TRUE` `FALSE` `NONE` | Literały wbudowane | `'True'` `'False'` `'None'` | `True` |
| `AND` `OR` `NOT` | Operatory logiczne | `'and'` `'or'` `'not'` | `and` |
| **Operatory** | | | |
| `ARROW` | Typ zwracany funkcji | `'->'` | `->` |
| `PLUS` `MINUS` | Dodawanie/odejmowanie | `'+'` `'-'` | `+` |
| `STAR` `DIV` `MOD` | Mnożenie/dzielenie/modulo | `'*'` `'/'` `'%'` | `*` |
| `ASSIGN` | Przypisanie | `'='` | `=` |
| `EQ` `NEQ` | Równość/nierówność | `'=='` `'!='` | `==` |
| `LT` `GT` `LE` `GE` | Porównania | `'<'` `'>'` `'<='` `'>='` | `<=` |
| **Znaki przestankowe** | | | |
| `LPAREN` `RPAREN` | Nawiasy okrągłe | `'('` `')'` | `(` |
| `LBRACK` `RBRACK` | Nawiasy kwadratowe | `'['` `']'` | `[` |
| `LBRACE` `RBRACE` | Nawiasy klamrowe | `'{'` `'}'` | `{` |
| `COLON` `COMMA` `DOT` | Dwukropek/przecinek/kropka | `':'` `','` `'.'` | `:` |
| **Literały i identyfikatory** | | | |
| `FLOAT` | Liczba zmiennoprzecinkowa | `DIGIT+ '.' DIGIT* \| '.' DIGIT+` | `3.14`, `.5` |
| `INT` | Liczba całkowita | `DIGIT+` | `42` |
| `STRING` | Łańcuch znaków (też potrójne `"""`) | `'"' (... )* '"'` itd. | `"tekst"`, `'a'` |
| `ID` | Identyfikator | `[a-zA-Z_][a-zA-Z0-9_]*` | `my_var` |

## Gramatyka formatu

Gramatyka w notacji generatora **ANTLR 4** (bez akcji). Pełne pliki znajdują się
w katalogu `grammar/` (`PythonRustLexer.g4`, `PythonRustParser.g4`). Poniżej
gramatyka parsera.

```antlr
parser grammar PythonRustParser;

options { tokenVocab = PythonRustLexer; }

// --- POZIOM NAJWYŻSZY ---
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

// --- INSTRUKCJE PROSTE ---
// Obejmuje instrukcję wyrażeniową, przypisanie (także łańcuchowe),
// rozpakowanie krotki (a, b = ...) oraz przypisanie z adnotacją (x: int = ...).
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

// --- INSTRUKCJE ZŁOŻONE ---
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

// --- PARAMETRY / ARGUMENTY / CELE PRZYPISANIA ---
parameters    : param (COMMA param)* COMMA? ;
param         : ID (COLON type)? (ASSIGN expr)? ;

arglist       : argument (COMMA argument)* COMMA? ;
argument      : ID ASSIGN expr   # KwArg
              | expr             # PosArg ;

// cele pętli for / wyrażeń listowych (nazwy, także zagnieżdżone krotki nazw)
target_list   : target (COMMA target)* COMMA? ;
target        : ID
              | LPAREN target_list RPAREN
              | LBRACK target_list RBRACK ;

// Lista wyrażeń oddzielonych przecinkami. Staje się KROTKĄ, gdy zawiera więcej
// niż jeden element lub kończy się przecinkiem; w przeciwnym razie to pojedyncze
// wyrażenie.
testlist      : expr (COMMA expr)* COMMA? ;

// Adnotacja typu, np. int, float, str, list[int], tuple[int, str], dict[str, int].
type          : ID (LBRACK type (COMMA type)* RBRACK)?
              | NONE ;

// --- WYRAŻENIA (priorytety: pierwsza alternatywa = najwyższy) ---
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

// --- ATOMY (literały, identyfikatory, kolekcje, krotki) ---
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

// --- KOLEKCJE I WYRAŻENIA LISTOWE ---
list_maker    : LBRACK ( expr comp_clause                // wyrażenie listowe
                       | expr (COMMA expr)* COMMA?        // literał listy
                       )? RBRACK ;

set_or_dict   : LBRACE ( dict_kv comp_clause             // wyrażenie słownikowe
                       | dict_kv (COMMA dict_kv)* COMMA?  // literał słownika
                       | expr comp_clause                // wyrażenie zbioru
                       | expr (COMMA expr)* COMMA?        // literał zbioru
                       )? RBRACE ;

dict_kv       : expr COLON expr ;
comp_clause   : FOR target_list IN expr (IF expr)? comp_clause? ;
```

## Informacje o stosowanych generatorach skanerów/parserów

- **ANTLR 4.13.2** – generator leksera i parsera (https://www.antlr.org).
  Generacja kodu C++ poleceniem:
  `java -jar antlr-4.13.2-complete.jar -Dlanguage=Cpp -visitor ...`
- **antlr4-cpp-runtime 4.13.2** – biblioteka uruchomieniowa ANTLR dla C++
  (kompilowana lokalnie do statycznej biblioteki `libantlr4-runtime.a`).
- Obsługa wcięć (`INDENT`/`DEDENT`) i łączenia linii: własna klasa
  `PythonLexerBase` (C++), wskazana opcją `superClass` w gramatyce leksera.

Pliki generowane przez ANTLR znajdują się w `src/generated/`.

## Krótka instrukcja obsługi

### Wymagania

Na ścieżce `PATH` muszą być dostępne:

- `java` – do uruchomienia generatora ANTLR,
- `g++` – kompilator C++17 (MinGW-w64 / MSYS2),
- `ar` – archiwizator (z pakietu binutils).

### Budowanie

W programie PowerShell, z katalogu projektu:

```powershell
./build.ps1            # generuje parser, buduje runtime (raz) i kompiluje pyrust.exe
./build.ps1 -Regen     # wymusza ponowną generację parsera z gramatyk
./build.ps1 -Clean     # czyści artefakty przed budową
```

Wynik: `build/pyrust.exe`.

### Uruchamianie konwertera

```powershell
build\pyrust.exe wejscie.py                # zapis do wejscie.rs (obok pliku)
build\pyrust.exe wejscie.py -o wynik.rs    # jawna ścieżka wyjścia
```

Następnie kod wynikowy można skompilować i uruchomić Rustem:

```powershell
rustc wynik.rs -o wynik.exe
./wynik.exe
```

## Przykład użycia

Plik wejściowy `examples/tuples.py`:

```python
def swap(a: int, b: int) -> tuple[int, int]:
    return b, a

point: tuple[int, int] = (3, 4)
x, y = point
print("x:", x, "y:", y)

pairs = [(1, 2), (3, 4), (5, 6)]
for left, right in pairs:
    print(left + right)
```

Polecenie:

```powershell
build\pyrust.exe examples/tuples.py
```

Wygenerowany fragment `examples/tuples.rs`:

```rust
fn swap(a: i64, b: i64) -> (i64, i64) {
    return (b, a);
}

fn main() {
    let mut point: (i64, i64) = (3, 4);
    let (mut x, mut y) = point;
    println!("{} {} {} {}", "x:".to_string(), x, "y:".to_string(), y);
    let mut pairs = vec![(1, 2), (3, 4), (5, 6)];
    for (left, right) in pairs.iter().cloned() {
        println!("{}", (left + right));
    }
}
```

W katalogu `examples/` znajdują się dalsze przykłady: `kalkulator.py`
(funkcje, warunki, pętla `while`) oraz `features.py` (klasy, wyrażenia listowe,
słowniki, zbiory) wraz z wynikami `*.rs`.

## Struktura projektu

```
grammar/      gramatyki ANTLR (lekser + parser)
src/          klasa PythonLexerBase, generator kodu Rust (main.cpp) i pliki ANTLR
src/generated wygenerowane przez ANTLR pliki C++
examples/     przykładowe pliki .py wraz z wynikami .rs
third_party/  narzędzie ANTLR (.jar) oraz źródła runtime C++
build/         artefakty kompilacji (pyrust.exe, libantlr4-runtime.a)
build.ps1      skrypt budujący
```

## Uwagi o zakresie tłumaczenia

Gramatyka rozpoznaje cały opisany podzbiór języka. Generacja kodu Rust jest
kompletna dla rdzenia języka (funkcje z adnotacjami typów, instrukcje sterujące,
wyrażenia, listy, krotki, podstawowe słowniki/zbiory i wyrażenia listowe).
Konstrukcje trudne do bezpośredniego odwzorowania w Rust (np. `try`/`except`,
dziedziczenie klas) tłumaczone są w sposób przybliżony – generator opiera się na
adnotacjach typów Pythona, które należy podawać dla parametrów i wyników funkcji.
