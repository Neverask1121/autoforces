import sys
from collections import deque

def solve():
    # Fast I/O: Reading all input at once
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    m = int(input_data[1])
    s = int(input_data[2])
    
    # Adjacency list for BLOCKED roads
    adj = [set() for _ in range(n + 1)]
    ptr = 3
    for _ in range(m):
        u = int(input_data[ptr])
        v = int(input_data[ptr+1])
        adj[u].add(v)
        adj[v].add(u)
        ptr += 2
        
    distances = [-1] * (n + 1)
    distances[s] = 0
    
    # We use two lists to manage unvisited nodes efficiently
    # This acts like a manual filter to avoid O(N^2)
    unvisited = set(range(1, n + 1))
    unvisited.remove(s)
    
    queue = deque([s])
    
    while queue:
        u = queue.popleft()
        
        # We need to find nodes in 'unvisited' NOT in adj[u]
        # We create a new set of nodes that REMAIN unvisited
        next_unvisited = set()
        for v in unvisited:
            if v in adj[u]:
                # This node is blocked from u, keep it in unvisited for later
                next_unvisited.add(v)
            else:
                # Found a hidden passage!
                distances[v] = distances[u] + 1
                queue.append(v)
        
        # Update unvisited to only contain those we couldn't reach from u
        unvisited = next_unvisited
            
    # Output formatting
    out = []
    for i in range(1, n + 1):
        if i != s:
            out.append(str(distances[i]))
    
    sys.stdout.write(" ".join(out) + "\n")

if __name__ == "__main__":
    solve()