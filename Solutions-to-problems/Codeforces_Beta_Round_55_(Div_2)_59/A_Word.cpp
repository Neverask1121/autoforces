#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int upper = 0, lower = 0;

    // Count uppercase and lowercase letters
    for(char c : s)
    {
        if(c >= 'A' && c <= 'Z')
            upper++;
        else
            lower++;
    }

    // Convert accordingly
    if(upper > lower)
    {
        for(char &c : s)
            c = toupper(c);
    }
    else
    {
        for(char &c : s)
            c = tolower(c);
    }

    cout << s;

    return 0;
}
