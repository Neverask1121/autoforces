#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    int mx = n;
    int i = 0;

    // Find first position where order breaks
    while (i < n && p[i] == mx) {
      mx--;
      i++;
    }

    // If fully correct, print as is
    if (i == n) {
      for (int x : p)
        cout << x << " ";
      cout << "\n";
      continue;
    }

    // Find position of mx
    int pos = i;
    while (p[pos] != mx)
      pos++;

    // Reverse the segment
    reverse(p.begin() + i, p.begin() + pos + 1);

    // Output
    for (int x : p)
      cout << x << " ";
    cout << "\n";
  }

  return 0;
}
