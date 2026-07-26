using namespace std;
#include <bits/stdc++.h>
int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long one = ceil((double)a/c);
    long long two = ceil((double)b/c);
    cout << one*two << endl;
    return 0;
}