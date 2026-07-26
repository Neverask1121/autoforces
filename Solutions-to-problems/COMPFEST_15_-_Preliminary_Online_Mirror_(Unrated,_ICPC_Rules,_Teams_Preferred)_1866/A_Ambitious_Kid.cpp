#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int answer = INT_MAX;
    while(N--){
      int A;
      cin >> A;
      answer = min(answer, abs(A));
    }
    cout << answer << endl;
    return 0;
}