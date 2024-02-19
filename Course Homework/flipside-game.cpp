

#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

string New_String(string old, int top, int bot) {
    swap(old[top], old[bot]);
    swap(old[top+1], old[bot+1]);
    swap(old[top+2], old[bot+2]);
    return old;
}
bool Check_Input(string s) {
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]) || s[i] == s[i + 1]) {
            return false;
        }
    }
    return true;
}
int main()
{
    string input{ "" };
    cout << "enter sequence to find" << endl;
    cin >> input;
    bool isNum = Check_Input(input);
    while (input.size() != 10 || !isNum) {
        cin.clear();
        cout << "invalid sequence" << endl;
        cin >> input;
        isNum = Check_Input(input);
    }
    map<string, int> moveCount;
    moveCount[input] = 0;
    queue<string> q;
    q.push(input);
    string endState{ "0123456789" };
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        int moves{ moveCount[current] };
        if (current == endState) {
            cout << moves << endl;
            return 0;
        }
        ++moves;
        for (int i = 0; i < 3; i++) {
            for (int j = 5; j < 8; j++) {
                string next = New_String(current, i, j);
                if (moveCount.find(next) == moveCount.end()) {
                    moveCount[next] = moves;
                    q.push(next);
                }
            }
        }
    }
}
