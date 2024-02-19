#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 40;
	int f[1000];
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		cout << f[i] << endl;
	}
}
