#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int counter;
    cin >> counter;
    for(int i = 0 ; i< counter ; i++){
        int a, b;
        cin >>a>>b;
        int division = a/b;
        int result = ((division+1)*b)-a;
        if(result == b){
            result =0;
        }
        cout << result << endl;
    }
    return 0;
}
