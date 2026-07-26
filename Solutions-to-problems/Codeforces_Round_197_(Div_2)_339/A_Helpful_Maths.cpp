/*#include <string.h>
#include <cctype>
using namespace std;
#include <iostream>
int main(){
    string s;
    cin >> s;
    int count=0;
    int cnt=0;
    int arr[count];
    //taking the input from the user can be anything.
    for (int n=0;n<.length();n++)
    {
        if (isdigit(s[i])) {
            arr[count] = s[i];
            count++;
        }
        if (isdigit(s[i])){
            for (int i=0 ; i<count ; i++)
            {
                for (int j = i ; j <count;i++ )
                {
                    int temp = arr[j]
                    arr[j] = arr [j+1];
                    arr[j+1] = temp; 
                }
            }
        }

        if (isdigit(s[i])){
            s[i]=arr[cnt];
        }
        


    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<char> nums;

    // extract digits
    for (char c : s) {
        if (isdigit(c)) {
            nums.push_back(c);
        }
    }

    // sort digits
    sort(nums.begin(), nums.end());

    // print result
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1)
            cout << "+";
    }

    return 0;
}
