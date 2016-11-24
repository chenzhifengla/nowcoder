#include <iostream>
using namespace std;

int A, B;
double minpay, maxpay;

int main() {
	while (cin >> A >> B) {
		minpay = (double)A / 19 * 20;
		if (A / 19 * 19 == A && A / 19 * 20 % 5 == 0)
			minpay -= 5;
		maxpay = (double)A / 9 * 10;
		if (maxpay < 0) maxpay = B;
		if (B < minpay) {
			cout << 0 << endl;
		}
		else if (B <= maxpay) {
			cout << B / 5 - (int)minpay / 5 << endl;
		}
		else {
			cout << (int)maxpay / 5 - (int)minpay / 5 << endl;
		}
	}
	return 0;
}