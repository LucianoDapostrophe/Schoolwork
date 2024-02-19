// greedy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "input the number of coin denominations\n";
    int n;
    cin >> n;
    vector<int> denominations;
    cout << "input denominations\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        denominations.push_back(val);
    }
    sort(denominations.begin(), denominations.end());
    cout << "\ninput target sum\n";
    int target;
    cin >> target;
    int counter{0};
    while (target != 0) {
        for (int i = n - 1; i >= 0; i--) {
            if (target - denominations[i] >= 0) {
                target -= denominations[i];
                counter++;
                break;
            }
        }
    }
    cout << counter << " coins required\n";
}