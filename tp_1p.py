from time import perf_counter

# Algorithm 1: AR(n, c)
def AR(n, c):
    if n > 0:
        c[0] += 1
        AR(n - 1, c)
        AR(n - 1, c)


# Algorithm 2: F(n)
def F(n):
    if n <= 1:
        return 1
    return F(n - 1) + F(n - 2)


# Test values
values = [10, 20, 30]

print("RECURSIVE ALGORITHM PERFORMANCE")
print("=" * 45)

for n in values:
    # Test AR
    c = [0]

    start = perf_counter()
    AR(n, c)
    time_ar = perf_counter() - start

    # Test F
    start = perf_counter()
    result = F(n)
    time_f = perf_counter() - start

    print(f"\nn = {n}")
    print(f"AR calls: {c[0]:,}")
    print(f"AR time: {time_ar:.6f} seconds")
    print(f"F(n): {result}")
    print(f"F time: {time_f:.6f} seconds")
