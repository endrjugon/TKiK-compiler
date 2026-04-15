# Konwerter Python do Rust

## Autorzy: 
* **Andrzej Gondek**, 
* **Krzysztof Gniewek**
## Dane kontaktowe :  
* Andrzej Gondek -   
* Krzysztof Gniewek - gniewek@student.agh.edu.pl

## Założenia programu
Celem projektu jest stworzenie narzędzia które tłumaczy określony fragment kodu napisany w języku Python na bezpieczny, statycznie typowany i wydajny kod w języku Rust.

### Rodzaj translatora - Konwerter
Program przyjmuje na wejściu plik z kodem źródłowym Pythona (`.py`), obsługujący podstawowe struktury (pętle, instrukcje warunkowe), proste operacje arytmetyczne i definicje funkcji z adnotacjami typów.

### Wynik działania programu to plik w języku Rust (`.rs`), który realizuje tę samą logikę.
* Wejście: Skrypt `kalkulator.py` (Python)
* Wyjście: Plik `kalkulator.rs` (Rust), gotowy do skompilowania narzędziem `rustc`.

### Planowany język implementacji
* **Python 3.13**

### Sposób realizacji skanera/parsera
Użycie zewnętrznego generatora skanerów i parserów dla języka Python – Lark
