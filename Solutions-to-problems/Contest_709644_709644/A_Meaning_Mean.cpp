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

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> temp = a;

        while(temp.size() > 1) {
            int sum = temp[0] + temp[1];
            int result = sum / 2;

            temp.erase(temp.begin());
            temp.erase(temp.begin());

            temp.push_back(result);

            sort(temp.begin(), temp.end());
        }

        int answer = temp[0];
        cout << answer << endl;
    }

    return 0;
}