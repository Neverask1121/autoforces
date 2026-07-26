#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string vowels = "aoyeui";
    string result = "";

    for (char c : s) {
        char lower = tolower(c);
        if (vowels.find(lower) == string::npos) {
            result += '.';
            result += lower;
        }
    }

    cout << result << endl;
    return 0;
}
