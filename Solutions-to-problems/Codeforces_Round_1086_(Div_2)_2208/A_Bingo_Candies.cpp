#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--) {
        int sz;
        cin >> sz;
        map<int,int> cnt;
        for(int r = 0; r < sz*sz; r++){
            int val; cin >> val;
            cnt[val]++;
        }
        bool valid = true;
        int limit = sz*(sz-1);
        for(auto& [key, amount] : cnt){
            if(amount > limit){
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << "\n";
    }
}