#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int in;
    cin >> in;
    for(int i = 1 ; i<= in ;i++){
        if(i == 1 && i != in){
            cout << "I hate" << " that ";
        }
        if(i == 1 && i == in){
            cout << "I hate it";
        }
        else if(i%2 == 0 && i != in && i != 1){
            cout << "I love" << " that ";

        }
        else if(i%2 != 0 && i != in && i != 1){
            cout << "I hate" << " that ";
        }
        else if(i%2 == 0 && i == in){
            cout << "I love it";
        }
        else if(i%2 != 0 && i == in){
            cout << "I hate it";
        }
    }
    return 0;
}