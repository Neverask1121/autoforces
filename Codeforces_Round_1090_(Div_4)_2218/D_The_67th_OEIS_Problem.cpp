#include <bits/stdc++.h>
using namespace std;

vector<long long> getPrimes(int cnt) {
    vector<long long> primes;
    long long num = 2;
    while ((int)primes.size() < cnt) {
        bool ok = true;
        for (long long i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                ok = false;
                break;
            }
        }
        if (ok) primes.push_back(num);
        num++;
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;

        vector<long long> primes = getPrimes(m + 1);
        vector<long long> ans;

        for (int i = 0; i < m; i++) {
            ans.push_back(primes[i] * primes[i + 1]);
        }

        for (auto x : ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}