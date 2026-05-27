def add(a: int, b: int) -> int:
    return a + b


def classify(n: int) -> str:
    if n < 0:
        return "negative"
    elif n == 0:
        return "zero"
    else:
        return "positive"


def factorial(n: int) -> int:
    result = 1
    i = 2
    while i <= n:
        result = result * i
        i = i + 1
    return result


x = 7
y = 5
print("sum:", add(x, y))
print("class:", classify(x - 12))
print("factorial:", factorial(x))
