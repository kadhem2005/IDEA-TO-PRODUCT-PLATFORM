
import random
from time import perf_counter

# Algorithm 1: Nested-loop sorting (O(n^2))
def algorithm1(T):
    T = T.copy()

    for i in range(len(T)):
        for j in range(i + 1, len(T)):
            if T[j] <= T[i]:
                T[i], T[j] = T[j], T[i]

    return T

# Algorithm 2: Merge sort (O(n log n))
def algorithm2(T):
    if len(T) <= 1:
        return T.copy()

    middle = len(T) // 2

    left = algorithm2(T[:middle])
    right = algorithm2(T[middle:])

    result = []
    i = 0
    j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])

    return result

# Test both algorithms
sizes = [1000, 3000, 5000, 10000]

print("Comparing sorting algorithms")
print("-" * 55)

for n in sizes:
    original = [random.randint(0, 100000) for _ in range(n)]

    start = perf_counter()
    result1 = algorithm1(original)
    time1 = perf_counter() - start

    start = perf_counter()
    result2 = algorithm2(original)
    time2 = perf_counter() - start

    print(f"\nArray size: {n}")
    print(f"Algorithm 1 (O(n^2)):    {time1:.6f} seconds")
    print(f"Algorithm 2 (O(n log n)): {time2:.6f} seconds")

    print("Algorithm 1 correct:", result1 == sorted(original))
    print("Algorithm 2 correct:", result2 == sorted(original))