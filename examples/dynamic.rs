#![allow(dead_code, unused_variables, unused_mut, unused_parens, unused_imports,
         non_snake_case, unreachable_code, unused_assignments, path_statements)]
use std::cell::RefCell;
use std::rc::Rc;

#[derive(Clone)]
enum Value {
    None,
    Int(i64),
    Float(f64),
    Bool(bool),
    Str(String),
    List(Rc<RefCell<Vec<Value>>>),
    Tuple(Vec<Value>),
    Dict(Rc<RefCell<Vec<(Value, Value)>>>),
    Set(Rc<RefCell<Vec<Value>>>),
}

fn values_equal(a: &Value, b: &Value) -> bool {
    match (a, b) {
        (Value::None, Value::None) => true,
        (Value::Int(x), Value::Int(y)) => x == y,
        (Value::Float(x), Value::Float(y)) => x == y,
        (Value::Int(x), Value::Float(y)) => (*x as f64) == *y,
        (Value::Float(x), Value::Int(y)) => *x == (*y as f64),
        (Value::Bool(x), Value::Bool(y)) => x == y,
        (Value::Str(x), Value::Str(y)) => x == y,
        (Value::Tuple(x), Value::Tuple(y)) => {
            x.len() == y.len() && x.iter().zip(y.iter()).all(|(p, q)| values_equal(p, q))
        }
        (Value::List(x), Value::List(y)) | (Value::Set(x), Value::Set(y)) => {
            let x = x.borrow();
            let y = y.borrow();
            x.len() == y.len() && x.iter().zip(y.iter()).all(|(p, q)| values_equal(p, q))
        }
        _ => false,
    }
}

impl Value {
    fn list(v: Vec<Value>) -> Value { Value::List(Rc::new(RefCell::new(v))) }
    fn set(v: Vec<Value>) -> Value {
        let mut out: Vec<Value> = Vec::new();
        for item in v {
            if !out.iter().any(|e| values_equal(e, &item)) { out.push(item); }
        }
        Value::Set(Rc::new(RefCell::new(out)))
    }
    fn dict(pairs: Vec<(Value, Value)>) -> Value {
        let mut out: Vec<(Value, Value)> = Vec::new();
        for (k, v) in pairs {
            if let Some(slot) = out.iter_mut().find(|p| values_equal(&p.0, &k)) {
                slot.1 = v;
            } else {
                out.push((k, v));
            }
        }
        Value::Dict(Rc::new(RefCell::new(out)))
    }

    fn is_truthy(&self) -> bool {
        match self {
            Value::None => false,
            Value::Bool(b) => *b,
            Value::Int(n) => *n != 0,
            Value::Float(f) => *f != 0.0,
            Value::Str(s) => !s.is_empty(),
            Value::Tuple(v) => !v.is_empty(),
            Value::List(v) | Value::Set(v) => !v.borrow().is_empty(),
            Value::Dict(d) => !d.borrow().is_empty(),
        }
    }

    fn to_f64(&self) -> f64 {
        match self {
            Value::Int(n) => *n as f64,
            Value::Float(f) => *f,
            Value::Bool(b) => if *b { 1.0 } else { 0.0 },
            _ => panic!("not a number"),
        }
    }
    fn as_index(&self) -> i64 {
        match self {
            Value::Int(n) => *n,
            Value::Bool(b) => if *b { 1 } else { 0 },
            _ => panic!("index must be an integer"),
        }
    }

    fn add(&self, other: &Value) -> Value {
        match (self, other) {
            (Value::Int(a), Value::Int(b)) => Value::Int(a + b),
            (Value::Str(a), Value::Str(b)) => Value::Str(format!("{}{}", a, b)),
            (Value::Tuple(a), Value::Tuple(b)) => {
                let mut v = a.clone();
                v.extend(b.iter().cloned());
                Value::Tuple(v)
            }
            (Value::List(a), Value::List(b)) => {
                let mut v = a.borrow().clone();
                v.extend(b.borrow().iter().cloned());
                Value::list(v)
            }
            _ => Value::Float(self.to_f64() + other.to_f64()),
        }
    }
    fn sub(&self, other: &Value) -> Value {
        match (self, other) {
            (Value::Int(a), Value::Int(b)) => Value::Int(a - b),
            _ => Value::Float(self.to_f64() - other.to_f64()),
        }
    }
    fn mul(&self, other: &Value) -> Value {
        match (self, other) {
            (Value::Int(a), Value::Int(b)) => Value::Int(a * b),
            (Value::Str(a), Value::Int(b)) => Value::Str(a.repeat((*b).max(0) as usize)),
            _ => Value::Float(self.to_f64() * other.to_f64()),
        }
    }
    fn div(&self, other: &Value) -> Value { Value::Float(self.to_f64() / other.to_f64()) }
    fn rem(&self, other: &Value) -> Value {
        match (self, other) {
            (Value::Int(a), Value::Int(b)) => Value::Int(a % b),
            _ => Value::Float(self.to_f64() % other.to_f64()),
        }
    }
    fn neg(&self) -> Value {
        match self {
            Value::Int(a) => Value::Int(-a),
            Value::Float(a) => Value::Float(-a),
            _ => panic!("bad operand for unary -"),
        }
    }

    fn eq_(&self, other: &Value) -> Value { Value::Bool(values_equal(self, other)) }
    fn ne_(&self, other: &Value) -> Value { Value::Bool(!values_equal(self, other)) }
    fn order(&self, other: &Value) -> std::cmp::Ordering {
        match (self, other) {
            (Value::Str(a), Value::Str(b)) => a.cmp(b),
            _ => self.to_f64().partial_cmp(&other.to_f64()).unwrap_or(std::cmp::Ordering::Equal),
        }
    }
    fn lt(&self, o: &Value) -> Value { Value::Bool(self.order(o) == std::cmp::Ordering::Less) }
    fn gt(&self, o: &Value) -> Value { Value::Bool(self.order(o) == std::cmp::Ordering::Greater) }
    fn le(&self, o: &Value) -> Value { Value::Bool(self.order(o) != std::cmp::Ordering::Greater) }
    fn ge(&self, o: &Value) -> Value { Value::Bool(self.order(o) != std::cmp::Ordering::Less) }

    fn index(&self, key: &Value) -> Value {
        match self {
            Value::List(v) | Value::Set(v) => {
                let v = v.borrow();
                let mut i = key.as_index();
                if i < 0 { i += v.len() as i64; }
                v[i as usize].clone()
            }
            Value::Tuple(v) => {
                let mut i = key.as_index();
                if i < 0 { i += v.len() as i64; }
                v[i as usize].clone()
            }
            Value::Str(s) => {
                let chars: Vec<char> = s.chars().collect();
                let mut i = key.as_index();
                if i < 0 { i += chars.len() as i64; }
                Value::Str(chars[i as usize].to_string())
            }
            Value::Dict(d) => {
                let d = d.borrow();
                for (k, val) in d.iter() {
                    if values_equal(k, key) { return val.clone(); }
                }
                panic!("KeyError");
            }
            _ => panic!("value is not subscriptable"),
        }
    }
    fn set_index(&self, key: &Value, val: Value) {
        match self {
            Value::List(v) => {
                let mut v = v.borrow_mut();
                let mut i = key.as_index();
                if i < 0 { i += v.len() as i64; }
                v[i as usize] = val;
            }
            Value::Dict(d) => {
                let mut d = d.borrow_mut();
                for pair in d.iter_mut() {
                    if values_equal(&pair.0, key) { pair.1 = val; return; }
                }
                d.push((key.clone(), val));
            }
            _ => panic!("value does not support item assignment"),
        }
    }
    fn slice(&self, lo: &Value, hi: &Value) -> Value {
        let items = self.iter_values();
        let n = items.len() as i64;
        let mut a = match lo { Value::None => 0, _ => lo.as_index() };
        let mut b = match hi { Value::None => n, _ => hi.as_index() };
        if a < 0 { a += n; }
        if b < 0 { b += n; }
        a = a.max(0).min(n);
        b = b.max(0).min(n);
        let mut out: Vec<Value> = Vec::new();
        let mut i = a;
        while i < b { out.push(items[i as usize].clone()); i += 1; }
        if let Value::Str(_) = self {
            let s: String = out.iter().map(|v| match v { Value::Str(c) => c.clone(), _ => String::new() }).collect();
            return Value::Str(s);
        }
        Value::list(out)
    }
    fn append(&self, val: Value) {
        match self {
            Value::List(v) => v.borrow_mut().push(val),
            Value::Set(v) => {
                let mut v = v.borrow_mut();
                if !v.iter().any(|e| values_equal(e, &val)) { v.push(val); }
            }
            _ => panic!("value has no append"),
        }
    }
    fn len(&self) -> i64 {
        match self {
            Value::Str(s) => s.chars().count() as i64,
            Value::Tuple(v) => v.len() as i64,
            Value::List(v) | Value::Set(v) => v.borrow().len() as i64,
            Value::Dict(d) => d.borrow().len() as i64,
            _ => panic!("value has no len()"),
        }
    }
    fn iter_values(&self) -> Vec<Value> {
        match self {
            Value::List(v) | Value::Set(v) => v.borrow().clone(),
            Value::Tuple(v) => v.clone(),
            Value::Str(s) => s.chars().map(|c| Value::Str(c.to_string())).collect(),
            Value::Dict(d) => d.borrow().iter().map(|(k, _)| k.clone()).collect(),
            _ => panic!("value is not iterable"),
        }
    }

    fn show(&self, quote: bool) -> String {
        match self {
            Value::None => "None".to_string(),
            Value::Bool(b) => if *b { "True".to_string() } else { "False".to_string() },
            Value::Int(n) => n.to_string(),
            Value::Float(f) => {
                if f.fract() == 0.0 && f.is_finite() { format!("{:.1}", f) } else { format!("{}", f) }
            }
            Value::Str(s) => if quote { format!("'{}'", s) } else { s.clone() },
            Value::List(v) => {
                let v = v.borrow();
                let parts: Vec<String> = v.iter().map(|e| e.show(true)).collect();
                format!("[{}]", parts.join(", "))
            }
            Value::Set(v) => {
                let v = v.borrow();
                let parts: Vec<String> = v.iter().map(|e| e.show(true)).collect();
                format!("{{{}}}", parts.join(", "))
            }
            Value::Tuple(v) => {
                let parts: Vec<String> = v.iter().map(|e| e.show(true)).collect();
                if v.len() == 1 { format!("({},)", parts[0]) } else { format!("({})", parts.join(", ")) }
            }
            Value::Dict(d) => {
                let d = d.borrow();
                let parts: Vec<String> = d.iter()
                    .map(|(k, val)| format!("{}: {}", k.show(true), val.show(true)))
                    .collect();
                format!("{{{}}}", parts.join(", "))
            }
        }
    }
}

impl std::fmt::Display for Value {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "{}", self.show(false))
    }
}

fn py_print(args: &[Value]) {
    let parts: Vec<String> = args.iter().map(|a| a.show(false)).collect();
    println!("{}", parts.join(" "));
}
fn py_len(v: &Value) -> Value { Value::Int(v.len()) }
fn py_str(v: &Value) -> Value { Value::Str(v.show(false)) }
fn py_int(v: &Value) -> Value {
    match v {
        Value::Int(n) => Value::Int(*n),
        Value::Float(f) => Value::Int(*f as i64),
        Value::Bool(b) => Value::Int(if *b { 1 } else { 0 }),
        Value::Str(s) => Value::Int(s.trim().parse::<i64>().unwrap_or(0)),
        _ => panic!("int(): bad argument"),
    }
}
fn py_float(v: &Value) -> Value { Value::Float(v.to_f64()) }
fn py_abs(v: &Value) -> Value {
    match v {
        Value::Int(n) => Value::Int(n.abs()),
        Value::Float(f) => Value::Float(f.abs()),
        _ => panic!("abs(): bad argument"),
    }
}
fn py_min(a: &Value, b: &Value) -> Value {
    if a.order(b) == std::cmp::Ordering::Greater { b.clone() } else { a.clone() }
}
fn py_max(a: &Value, b: &Value) -> Value {
    if a.order(b) == std::cmp::Ordering::Less { b.clone() } else { a.clone() }
}
fn py_range(args: &[Value]) -> Value {
    let (start, stop, step) = match args.len() {
        1 => (0, args[0].as_index(), 1),
        2 => (args[0].as_index(), args[1].as_index(), 1),
        _ => (args[0].as_index(), args[1].as_index(), args[2].as_index()),
    };
    let mut out: Vec<Value> = Vec::new();
    let mut i = start;
    if step > 0 { while i < stop { out.push(Value::Int(i)); i += step; } }
    else if step < 0 { while i > stop { out.push(Value::Int(i)); i += step; } }
    Value::list(out)
}

fn describe(v: Value) -> Value {
    return v.clone();
    Value::None
}

fn main() {
    let mut x = Value::Int(5);
    let _ = py_print(&[x.clone()]);
    x = Value::Str("now a string".to_string());
    let _ = py_print(&[x.clone()]);
    x = Value::list(vec![Value::Int(1), Value::Str("two".to_string()), Value::Float(3.0), Value::Bool(true)]);
    let _ = py_print(&[x.clone(), py_len(&(x))]);
    let _ = py_print(&[describe(Value::Int(42))]);
    let _ = py_print(&[describe(Value::Str("hello".to_string()))]);
    let _ = py_print(&[describe(Value::list(vec![Value::Int(1), Value::Int(2)]))]);
    let mut data = Value::list(vec![Value::Int(1), Value::Int(2), Value::Int(3)]);
    let _ = (data).append(Value::Str("four".to_string()));
    let _ = (data).append(Value::None);
    let _ = py_print(&[data.clone()]);
    let mut mixed = Value::dict(vec![(Value::Str("name".to_string()), Value::Str("Ada".to_string())), (Value::Str("age".to_string()), Value::Int(36)), (Value::Str("tags".to_string()), Value::list(vec![Value::Int(1), Value::Int(2)]))]);
    let _ = py_print(&[(mixed).index(&(Value::Str("name".to_string()))), (mixed).index(&(Value::Str("age".to_string()))), (mixed).index(&(Value::Str("tags".to_string())))]);
}
