#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases;

    while(cases--) {

        int totalStudents;
        string directions;

        cin >> totalStudents;
        cin >> directions;

        vector<int> received(totalStudents + 2, 0);

        int holder = 1;
        received[holder] = 1;

        int passes = 0;

        while(passes < totalStudents) {

            char moveDirection = directions[holder - 1];

            if(moveDirection == 'R')
                holder = holder + 1;
            else
                holder = holder - 1;

            received[holder] = 1;
            passes++;
        }

        int answer = 0;

        for(int idx = 1; idx <= totalStudents; idx++) {
            if(received[idx])
                answer++;
        }

        cout << answer << "\n";
    }

    return 0;
}