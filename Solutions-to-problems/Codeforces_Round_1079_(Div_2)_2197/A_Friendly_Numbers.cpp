#include <bits/stdc++.h>
using namespace std;

int digitSum(long long n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        long long x;
        cin >> x;

        int count = 0;

        for(int s = 1; s <= 81; s++) {
            long long y = x + s;
            if(digitSum(y) == s) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}
