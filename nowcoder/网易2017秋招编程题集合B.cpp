#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int num = 0;
		int r = (int)sqrt(n);
		if (r * r == n) {
			num += 4;
		}
		for (int i = 1, j = r; i <= j;) {
			int p2 = i * i + j * j;
			if (p2 == n) {
				num += (i == j) ? 4 : 8;
				i++;
				j--;
			}
			else if (p2 > n) {
				j--;
			}
			else {
				i++;
			}
		}
		cout << num << endl;
	}
	return 0;
}