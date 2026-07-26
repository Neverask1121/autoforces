#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++){
            int a = i;
            int b = n + 2*i - 1;
            int c = n + 2*i;

            cout << a << " " << b << " " << c;
            if(i < n) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}