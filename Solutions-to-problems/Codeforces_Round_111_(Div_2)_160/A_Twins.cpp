#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    int total = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    int sum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        sum += a[i];
        count++;
        if(sum > total - sum){
            break;
        }
    }

    cout << count;

    return 0;
}