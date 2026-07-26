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
    while(t--){
      string x;
      cin >> x;
      int size = (int)x.size();
      int y = 1;
      for(int i = 0 ; i < size ; i++){
        y *= 10;
      }
      y+=1;
      cout << y << endl;
    }
    return 0;
}