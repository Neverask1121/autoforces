//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > h){
            count += 2;
        }
        else{
            count++;
        }
    }
    cout << count;
    //my code goes here
    return 0;
}