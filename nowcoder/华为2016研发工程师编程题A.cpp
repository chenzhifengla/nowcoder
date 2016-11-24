#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n) {
		if (n > 1000) n = 1000;
		int f = 0;
		for (int i = 2; i <= n; i++){
			f = (f + 3) % i;
		}
		cout << f << endl;
	}
	return 0;
}