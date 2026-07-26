#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int size;
    cin >> size;
    string ch;
    cin >> ch;
    set<char> letters;
    for (char s : ch){
        letters.insert(tolower(s));
    }
    if(letters.size()==26){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}