  // #include <bits/stdc++.h>

  // using namespace std;

  // #define ll long long
  // #define endl '\n'
  // #define all(x) (x).begin(), (x).end()

  // int main() {
  //     ios::sync_with_stdio(false);
  //     cin.tie(nullptr);

  //     int t;
  //     cin >> t;

  //     while(t--) {
  //         int n;
  //         cin >> n;

  //         vector<int> a(n);
  //         for(int i = 0; i < n; i++) {
  //             cin >> a[i];
  //         }

  //         sort(a.begin(), a.end());

  //         vector<int> temp = a;

  //         while(temp.size() > 1) {
  //             int sum = temp[0] + temp[1];
  //             int result = sum / 2;

  //             temp.erase(temp.begin());
  //             temp.erase(temp.begin());

  //             temp.push_back(result);

  //             sort(temp.begin(), temp.end());
  //         }

  //         int answer = temp[0];
  //         cout << answer << endl;
  //     }

  //     return 0;
  // }



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            cnt[c]++;
        }

        int different = 0;
        int only_one = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0) {
                different++;
                if (cnt[i] == 1) only_one++;
            }
        }

        int alice_moves = (n + 1) / 2; 
        int singletons_taken = (only_one + 1) / 2; 
        int remaining_moves = alice_moves - singletons_taken;
        int non_singleton_colors = different - only_one;

        int ans = 2 * singletons_taken + min(remaining_moves, non_singleton_colors);
        cout << ans << '\n';
    }

    return 0;
}