import sys

def solve():
    # Reading input
    try:
        line1 = sys.stdin.readline().split()
        if not line1: return
        n, k, d = map(int, line1)
        s = sys.stdin.readline().strip()
    except EOFError:
        return

    if k == 1:
        print(n)
        return

    # Polynomial Rolling Hash setup
    P = 31
    MOD = 10**9 + 9
    
    h = [0] * (n + 1)
    pow_p = [1] * (n + 1)
    for i in range(n):
        h[i+1] = (h[i] * P + (ord(s[i]) - ord('a') + 1)) % MOD
        pow_p[i+1] = (pow_p[i] * P) % MOD

    def get_hash(l, r): # 1-indexed [l, r]
        res = (h[r] - h[l-1] * pow_p[r-l+1]) % MOD
        return res if res >= 0 else res + MOD

    def check(length):
        if length == 0: return True
        # Check every possible starting position p
        # Max starting p such that p + (k-1)*d + length - 1 <= n
        max_p = n - (k - 1) * d - length + 1
        for p in range(1, max_p + 1):
            first_hash = get_hash(p, p + length - 1)
            possible = True
            for j in range(1, k):
                if get_hash(p + j * d, p + j * d + length - 1) != first_hash:
                    possible = False
                    break
            if possible:
                return True
        return False

    # Binary search for maximum L
    low = 0
    high = n - (k - 1) * d
    ans = 0
    
    while low <= high:
        mid = (low + high) // 2
        if mid == 0:
            low = mid + 1
            continue
        if check(mid):
            ans = mid
            low = mid + 1
        else:
            high = mid - 1
            
    print(ans)

solve()