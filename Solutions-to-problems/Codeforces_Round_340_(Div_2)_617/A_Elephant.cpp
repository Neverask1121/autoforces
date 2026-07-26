#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, count = 0;
    cin >> n;

    vector<int> iter = {5, 4, 3, 2, 1};
    for (int coin : iter){
        count += n / coin;
        n %= coin;
    }
    cout << count << endl;

    return 0;
}