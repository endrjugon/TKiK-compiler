#![allow(unused_mut, unused_variables, dead_code, unused_parens,
         unused_imports, non_snake_case, unreachable_code)]
use std::collections::{HashMap, HashSet};

fn divmod_pair(a: i64, b: i64) -> (i64, i64) {
    return ((a / b), (a % b));
}

fn swap(a: i64, b: i64) -> (i64, i64) {
    return (b, a);
}

fn main() {
    let mut point: (i64, i64) = (3, 4);
    let (mut x, mut y) = point;
    println!("{} {} {} {}", "x:".to_string(), x, "y:".to_string(), y);
    let mut a = 1;
    let mut b = 2;
    (a, b) = (b, a);
    println!("{} {} {}", "swapped:".to_string(), a, b);
    let mut pair = (10, 20);
    println!("{} {} {} {}", "first:".to_string(), pair.0, "second:".to_string(), pair.1);
    let mut singleton = (42,);
    println!("{} {}", "singleton:".to_string(), singleton.0);
    let mut pairs = vec![(1, 2), (3, 4), (5, 6)];
    for (left, right) in pairs.iter().cloned() {
        println!("{}", (left + right));
    }
}
