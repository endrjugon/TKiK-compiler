#![allow(unused_mut, unused_variables, dead_code, unused_parens,
         unused_imports, non_snake_case, unreachable_code)]
use std::collections::{HashMap, HashSet};

fn add(a: i64, b: i64) -> i64 {
    return (a + b);
}

fn classify(n: i64) -> String {
    if (n < 0) {
        return "negative".to_string();
    } else if (n == 0) {
        return "zero".to_string();
    } else {
        return "positive".to_string();
    }
}

fn factorial(n: i64) -> i64 {
    let mut result = 1;
    let mut i = 2;
    while (i <= n) {
        result = (result * i);
        i = (i + 1);
    }
    return result;
}

fn main() {
    let mut x = 7;
    let mut y = 5;
    println!("{} {}", "sum:".to_string(), add(x, y));
    println!("{} {}", "class:".to_string(), classify((x - 12)));
    println!("{} {}", "factorial:".to_string(), factorial(x));
}
