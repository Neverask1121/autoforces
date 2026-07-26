// By Aditya Bhandari, IIIT Vadodara, CSE
// in cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  string c;
  cin >> c;
  string reversed = s;                       // copy original string
  reverse(reversed.begin(), reversed.end()); // reverse the copy

  if (reversed == c)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
