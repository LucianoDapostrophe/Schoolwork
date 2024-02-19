// dp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits.h>
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
    cout << "\ninput target sum\n";
    int target;
    cin >> target;
    vector<int> coins(target + 1, INT_MAX);
    coins[0] = 0;
    for (int i = 1; i <= target; i++) {
        for (int value : denominations) {

            if (value <= i && coins[i - value] != INT_MAX) {
                coins[i] = min(coins[i], coins[i - value] + 1);
            }
        }
    }

    cout << coins[target] << " coins required\n";
}
/*Question 3:

Same output: denominations 1, 5, 10, 25, 100.  Find 146
             denominations 5.  Find 10
             denominations 1 2 3 5 7 11 13 17 19 23 29 31 37 41 43. Find 934
             
Different output: denominations 1, 12, 19. Find 25
                  denominations 1, 11, 80. Find 88
                  denominations 1, 20, 37. Find 40*/
