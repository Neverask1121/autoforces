// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    // Write C++ code here
    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        vector<int>arr(m);
        for(int i= 0 ; i < m ; i++){
            cin >> arr[i];
        }
        for(int i = 1 ; i < m ; i++){
            if(arr[i-1]<=arr[i]){
                arr[i] = arr[i-1];
            }
        }
        int sum = 0;
        for(int i = 0 ; i < m ; i++){
            sum += arr[i];
        }
        cout << sum << endl;
    }
    return 0;
}