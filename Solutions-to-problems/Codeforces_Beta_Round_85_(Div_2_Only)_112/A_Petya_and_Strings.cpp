#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        char c1 = tolower(a[i]);
        char c2 = tolower(b[i]);

        if (c1 < c2)
        {
            cout << -1 << endl;
            return 0;
        }
        else if (c1 > c2)
        {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
