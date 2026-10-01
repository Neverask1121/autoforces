#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, p;
        cin >> n >> p;
        vector<long long>a(n), b(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < n ; i++){
            cin >> b[i];
        }
        vector<pair<long long, long long>>v;
        for(int i = 0 ; i < n ; i++){
            v.push_back({b[i], a[i]});
        }
        sort(v.begin(), v.end());
        long long sum = p;
        long long m = n - 1;
        long long i = 0;
        while(m > 0 && i < n){
            if(v[i].first >= p){
                break;
            }
            long long people = min(m, v[i].second);
            sum += people*v[i].first;
            m -= people;
            i++;
        }
        sum += m*p;
        cout << sum << endl;
    }
}