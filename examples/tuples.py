# Demonstration of the tuple support added to the grammar.

def divmod_pair(a: int, b: int) -> tuple[int, int]:
    return a / b, a % b


def swap(a: int, b: int) -> tuple[int, int]:
    return b, a


point: tuple[int, int] = (3, 4)
x, y = point
print("x:", x, "y:", y)

a = 1
b = 2
a, b = b, a
print("swapped:", a, b)

pair = (10, 20)
print("first:", pair[0], "second:", pair[1])

singleton = (42,)
print("singleton:", singleton[0])

pairs = [(1, 2), (3, 4), (5, 6)]
for left, right in pairs:
    print(left + right)
