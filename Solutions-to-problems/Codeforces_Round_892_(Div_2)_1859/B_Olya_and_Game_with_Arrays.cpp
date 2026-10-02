#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long min_first=INT_MAX;
        long long min_second=INT_MAX;
        long long sum_of_second = 0;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int m;
            cin >> m;
            vector<long long>a(m);
            for(int i = 0; i < m; i++){
                cin >> a[i];
            }
            sort(a.begin(), a.end());
            sum_of_second += a[1];
            min_first = min(min_first, a[0]);
            min_second = min(min_second, a[1]);
        }
        cout << sum_of_second + min_first - min_second << endl;
    }
    return 0;
}