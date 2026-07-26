#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int sz;
        cin >> sz;
        vector<int> arr(sz);
        for (int j = 0; j < sz; j++) cin >> arr[j];
        int count = 0;
        int peak = 0;
        for (int j = 0; j < sz; j++) {
            if (arr[j] >= peak) {
                count++;
                peak = arr[j];
            }
        }
        cout << count << "\n";
    }
    return 0;
}