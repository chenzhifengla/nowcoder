#include <iostream>
using namespace std;

int n;

int main() {
	while (cin >> n) {
		if (n % 8 == 0) {
			cout << n / 8 << endl;
		}
		else {
			int max_num = n / 8 + 1;
			int remain = max_num * 8 - n;
			if (remain % 2 != 0) {
				cout << "-1" << endl;
			}
			else {
				cout << max_num << endl;
			}
		}
	}
	return 0;
}