import sys

def solve():
    # Read number of test cases
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    results = []
    
    idx = 1
    for _ in range(t):
        n = int(input_data[idx])
        d = int(input_data[idx + 1])
        idx += 2
        
        possible = False
        current_power = 1
        
        # Check all possible powers of 2 that Alice could reach
        while current_power <= n:
            # If current stone index has same remainder as n when divided by d
            # Alice can reach n by repeatedly adding d
            if current_power % d == n % d:
                possible = True
                break
            current_power *= 2
            
        if possible:
            results.append("YES")
        else:
            results.append("NO")
            
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()