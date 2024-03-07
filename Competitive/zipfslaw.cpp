#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        map<string, int> words;
        string s;
        while (getline(cin, s) && s != "EndOfText") {
            for (char &c : s) {
                if (!isalpha(c)) {
                    c = ' ';
                }
                else {
                    c = tolower(c);
                }
            }
            istringstream ss(s);
            string temp;
            while (ss >> temp) {
                words[temp]++;
            }
        }
        bool wordFound = false;
        for (auto i = words.begin(); i != words.end(); i++) {
            if (i->second == n) {
                cout << i->first << endl;
                wordFound = true;
            }
        }
        if (!wordFound) {
            cout << "There is no such word." << endl;
        }
        cout << endl;
    }
}