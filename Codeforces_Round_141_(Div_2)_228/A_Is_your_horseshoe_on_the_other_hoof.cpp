#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int count=0;
    if(a == b || a == c || a == d){
        count++;
    }
    if(b == c || b == d){
        count++;
    }
    if(c == d){
        count++;
    }
    printf("%d", count);
    return 0;
}