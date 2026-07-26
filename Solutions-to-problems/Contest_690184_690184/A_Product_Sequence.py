import math

def solve():
    try:
        line = input().split()
        if not line: return
        n, k = map(int, line)
    except EOFError:
        return

    factors = []
    d = 2
    temp_n = n
    
    # Standard prime factorization up to sqrt(n)
    while d * d <= temp_n and len(factors) < k - 1:
        while temp_n % d == 0 and len(factors) < k - 1:
            factors.append(d)
            temp_n //= d
        d += 1
    
    # If we still need the k-th element and the remaining n is > 1
    if temp_n > 1:
        factors.append(temp_n)

    # Output validation
    if len(factors) < k:
        print("-1")
    else:
        print(*(factors))

solve()