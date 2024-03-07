#include <bits/stdc++.h>
using namespace std;

int reverse(int forward) {
    int backward = 0;
    for (int i = 0; i < 3; i++) {
        backward *= 10;
        backward += forward % 10;
        forward /= 10;
    }
    return backward;
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;
    cout << max(reverse(a), reverse(b));
}