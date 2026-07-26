#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s, x;
        cin >> n >> s >> x;
        int arr[n];
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        int difference = s-sum;
        if(difference % x == 0 && s >= sum){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        
    }
    return 0;
}