// roadmap2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

bool sortAnagrams(string s, string t) {
    if (s.length() == t.length()) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {
            return true;
        }
    }
    return false;
}

int main()
{
    string s = "rat";
    string t = "car";
    cout << boolalpha << sortAnagrams(s, t);
}


