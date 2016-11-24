#include <iostream>
using namespace std;

int main() {
	int a, b, c, a_sub_b, b_sub_c, a_add_b, b_add_c;
	while (cin >> a_sub_b >> b_sub_c >> a_add_b >> b_add_c) {
		a = (a_sub_b + a_add_b) / 2;
		b = a - a_sub_b;
		c = b - b_sub_c;
		if (a + b != a_add_b || b + c != b_add_c)
			cout << "No" << endl;
		else cout << a << " " << b << " " << c << endl;
	}
	return 0;
}