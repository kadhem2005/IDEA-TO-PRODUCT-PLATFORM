
def F(n):
    if n <= 1:
        return 1

    dp = [0] * (n + 1)

    dp[0] = 1
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + 2 * dp[i - 2]

    return dp[n]

# Test the function
for n in [0, 1, 2, 3, 4, 10, 20, 30]:
    print(f"F({n}) = {F(n)}")