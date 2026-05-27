# Demonstrates dynamic typing: no annotations, variables change type,
# heterogeneous collections.

x = 5
print(x)
x = "now a string"
print(x)
x = [1, "two", 3.0, True]
print(x, len(x))

def describe(v):
    return v

print(describe(42))
print(describe("hello"))
print(describe([1, 2]))

data = [1, 2, 3]
data.append("four")
data.append(None)
print(data)

mixed = {"name": "Ada", "age": 36, "tags": [1, 2]}
print(mixed["name"], mixed["age"], mixed["tags"])
