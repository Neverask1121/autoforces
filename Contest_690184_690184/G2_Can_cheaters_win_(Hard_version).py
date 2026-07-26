import sys

def solve():
    # Fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    k = int(input_data[1])
    s = input_data[2]

    # Rule: If K=1, the LCP is the length of the string itself
    if k == 1:
        print(n)
        return

    # --- Suffix Array Construction (O(N log N)) ---
    sa = list(range(n))
    rank = [ord(s[i]) for i in range(n)]
    k_step = 1
    
    while k_step < n:
        # We sort suffixes based on (rank[i], rank[i + k_step])
        # Using a single integer for sorting to speed up Python's sort
        key = [0] * n
        for i in range(n):
            first = rank[i]
            second = rank[i + k_step] if i + k_step < n else -1
            key[i] = (first << 32) + (second + 1)
        
        sa.sort(key=lambda x: key[x])
        
        new_rank = [0] * n
        for i in range(1, n):
            new_rank[sa[i]] = new_rank[sa[i-1]] + (1 if key[sa[i]] > key[sa[i-1]] else 0)
        rank = new_rank
        if rank[sa[n-1]] == n - 1:
            break
        k_step *= 2

    # --- LCP Array Construction (Kasai's Algorithm, O(N)) ---
    lcp = [0] * n
    inv_sa = [0] * n
    for i in range(n):
        inv_sa[sa[i]] = i
    
    h = 0
    for i in range(n):
        if inv_sa[i] > 0:
            j = sa[inv_sa[i] - 1]
            while i + h < n and j + h < n and s[i + h] == s[j + h]:
                h += 1
            lcp[inv_sa[i]] = h
            if h > 0:
                h -= 1

    # --- Sliding Window for max LCP of K suffixes (O(N)) ---
    # To find the LCP of K suffixes, we find the minimum LCP value 
    # in a window of size (K-1) in the LCP array.
    from collections import deque
    dq = deque()
    max_ans = 0
    # A window of K suffixes corresponds to K-1 LCP values
    window_limit = k - 1
    
    for i in range(1, n):
        # Maintain a monotonic queue for range minimum
        while dq and lcp[dq[-1]] >= lcp[i]:
            dq.pop()
        dq.append(i)
        
        # Remove indices that fall out of the sliding window
        if dq[0] <= i - window_limit:
            dq.popleft()
            
        # Once the window is full, the front of the deque is our range minimum
        if i >= window_limit:
            max_ans = max(max_ans, lcp[dq[0]])
            
    sys.stdout.write(str(max_ans) + '\n')

if __name__ == "__main__":
    solve()