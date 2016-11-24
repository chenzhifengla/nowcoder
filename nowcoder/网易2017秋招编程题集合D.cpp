#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n) {
		long long  f = 3, h = 0;
		while (--n) {
			h += 2 * f;
			f = h - f;
		}
		cout << f + h << endl;
	}
	return 0;
}