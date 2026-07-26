#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
      /* code */
      int n;cin >> n;
      vector<int>A(n);
      for (int i = 0; i < n; i++)
      {
        /* code */
        cin >> A[i];
      }
      sort(A.begin(), A.end());
      cout << A[n-1]-A[0]+1 << endl;
      
    }
    
    return 0;
}