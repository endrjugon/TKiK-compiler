class Counter:
    def __init__(self, start: int):
        self.value = start

    def increment(self):
        self.value = self.value + 1

    def get(self) -> int:
        return self.value


def squares(n: int) -> list[int]:
    return [i * i for i in range(n)]


def sum_list(xs: list[int]) -> int:
    total = 0
    for x in xs:
        total = total + x
    return total


nums = [1, 2, 3, 4, 5]
evens = [x for x in nums if x % 2 == 0]
print("evens:", evens)
print("squares:", squares(5))
print("sum:", sum_list(nums))

c = Counter(10)
c.increment()
c.increment()
print("counter:", c.get())

scores = {"alice": 90, "bob": 85}
print("alice:", scores["alice"])

uniq = {1, 2, 2, 3}
print("uniq size:", len(uniq))

i = 0
while i < 3:
    if i == 1:
        print("one")
    else:
        print("other")
    i = i + 1
