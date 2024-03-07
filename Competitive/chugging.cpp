#include <bits/stdc++.h>
using namespace std;

int drinkTime(int n, int time, int delay) {
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        totalTime += time + (delay * i);
    }
    return totalTime;
}

int main() {
    int n;
    int ta, da;
    int tb, db;
    cin >> n >> ta >> da >> tb >> db;
    if (drinkTime(n, ta, da) < drinkTime(n, tb, db)) {
        cout << "Alice";
    }
    else if (drinkTime(n, ta, da) == drinkTime(n, tb, db)) {
        cout << "=";
    }
    else {
        cout << "Bob";
    }
}