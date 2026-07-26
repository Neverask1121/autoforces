#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    int m;
    cin >> m;

    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
    }

    int mx = arr[0];
    for (int i = 1; i < m; i++) {
      if (arr[i] > mx) {
        mx = arr[i];
      }
    }

    cout << mx * m << endl;
  }
  return 0;
}
