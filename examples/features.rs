#![allow(unused_mut, unused_variables, dead_code, unused_parens,
         unused_imports, non_snake_case, unreachable_code)]
use std::collections::{HashMap, HashSet};

struct Counter {
    value: i64,
}

impl Counter {
    fn new(start: i64) -> Self {
        Counter {
            value: start,
        }
    }

    fn increment(&mut self) {
        self.value = (self.value + 1);
    }

    fn get(&self) -> i64 {
        return self.value;
    }

}

fn squares(n: i64) -> Vec<i64> {
    return (0..n).map(|i| (i * i)).collect::<Vec<_>>();
}

fn sum_list(xs: Vec<i64>) -> i64 {
    let mut total = 0;
    for x in xs.iter().cloned() {
        total = (total + x);
    }
    return total;
}

fn main() {
    let mut nums = vec![1, 2, 3, 4, 5];
    let mut evens = nums.iter().cloned().filter(|x| ((x % 2) == 0)).map(|x| x).collect::<Vec<_>>();
    println!("{} {:?}", "evens:".to_string(), evens);
    println!("{} {:?}", "squares:".to_string(), squares(5));
    println!("{} {}", "sum:".to_string(), sum_list(nums));
    let mut c = Counter::new(10);
    c.increment();
    c.increment();
    println!("{} {}", "counter:".to_string(), c.get());
    let mut scores = HashMap::from([("alice".to_string(), 90), ("bob".to_string(), 85)]);
    println!("{} {}", "alice:".to_string(), scores[&("alice".to_string())]);
    let mut uniq = HashSet::from([1, 2, 2, 3]);
    println!("{} {}", "uniq size:".to_string(), (uniq.len() as i64));
    let mut i = 0;
    while (i < 3) {
        if (i == 1) {
            println!("{}", "one".to_string());
        } else {
            println!("{}", "other".to_string());
        }
        i = (i + 1);
    }
}
