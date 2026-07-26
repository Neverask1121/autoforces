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
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        //input stage over
        //sorting elements
        int count =0;
        sort(all(a));
        if(n%2 == 0){
        
            int counter = n-1;
            for(int i = 0 ; i < n/2 ; i++){
                if(a[i] != a[counter]){
                    count++;
                }
                else if(a[i] == a[counter]){
                    continue;
                }
                counter--;
            }
        }
        else if(n%2 != 0){
            
            int counter = n-1;
            for(int i = 0 ; i < n/2 ; i++){
                if(a[i] != a[counter]){
                    count++;
                }
                else if(a[i] == a[counter]){
                    continue;
                }
                counter--;
            }
        }
        cout << count << endl;
    }
    return 0;
}