#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = 0;
    bool seen[26] = {false};

    for (int i = 0; i < s.length(); i++)
    {
        if (!seen[s[i] - 'a'])
        {
            seen[s[i] - 'a'] = true;
            n++;
        }
    }

    if (n % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}
