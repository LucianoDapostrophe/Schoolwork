#include <bits/stdc++.h>
using namespace std;

int digitMultiplier(int a) {
    int intermediate = a;
    while (intermediate > 9) {
        vector<int> digits;
        while (intermediate > 0) {
            int tmp = intermediate % 10;
            if (tmp != 0) {
                digits.push_back(tmp);
            }
            intermediate /= 10;
        }
        int result = digits[0];
        for (int i = 1; i < digits.size(); i++) {
            result *= digits[i];
        }
        intermediate = result;
    }
    return intermediate;
}

int main() {
    int x;
    cin >> x;
    cout << digitMultiplier(x);
}