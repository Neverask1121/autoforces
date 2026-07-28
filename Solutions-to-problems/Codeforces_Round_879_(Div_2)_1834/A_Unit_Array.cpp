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

        vector<int> a(n);
        int sum = 0;
        int count_minus = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            if(a[i] == -1)
                count_minus++;
        }

        int count = 0;

        while(sum < 0){
            sum += 2;
            count++;
            count_minus--;    // minimal fix
        }

        if(count_minus % 2 != 0)
            count++;

        cout << count << endl;
    }

    return 0;
}