#include <iostream>
using namespace std;

int n, a, num;

int gcd(int n1, int n2) {
	if (n2 == 0) return n1;
	else return gcd(n2, n1 % n2);
}

int main() {
	while (cin >> n >> a) {
		while (n--) {
			cin >> num;
			if (num <= a) {
				a += num;
			}
			else {
				a += gcd(a, num);
			}
		}
		cout << a << endl;
	}
	return 0;
}