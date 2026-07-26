// By Aditya Bhandari, IIIT Vadodara, CSE
// in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, n, w, sum = 0;
  cin >> k >> n >> w;
  while (w > 0) {
    sum += k * w;
    w--;
  }
  int answer = sum - n;
  if (answer > 0)
    cout << answer << endl;
  else
    cout << 0 << endl;
  // my code goes here
  return 0;
}