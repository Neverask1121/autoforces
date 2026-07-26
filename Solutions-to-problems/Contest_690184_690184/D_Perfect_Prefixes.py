import sys

def solve():
    # Read number of test cases
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    t = int(input_data[ptr])
    ptr += 1
    
    results = []
    for _ in range(t):
        n = int(input_data[ptr])
        ptr += 1
        # Read permutation (1-indexed based on problem description)
        a = list(map(int, input_data[ptr : ptr + n]))
        ptr += n
        
        # Calculate number of cycles
        visited = [False] * n
        num_cycles = 0
        
        for i in range(n):
            if not visited[i]:
                num_cycles += 1
                curr = i
                # Traverse the cycle
                # Note: permutation values are 1 to n, so we subtract 1 for 0-indexing
                while not visited[curr]:
                    visited[curr] = True
                    curr = a[curr] - 1
        
        # Min swaps = n - number of cycles
        results.append(str(n - num_cycles))
    
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    solve()