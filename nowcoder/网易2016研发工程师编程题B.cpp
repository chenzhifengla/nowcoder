#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int r, pt[3][2], enemy[2];
	while (cin >> r) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> pt[i][j];
			}
		}
		for (int i = 0; i < 2; i++) {
			cin >> enemy[i];
		}
		int r2 = r * r;
		int damage = 0;
		for (int i = 0; i < 3; i++) {
			if (pow(pt[i][0] - enemy[0], 2) + pow(pt[i][1] - enemy[1], 2) <= r2) {
				damage++;
			}
		}
		cout << damage << "x" << endl;
	}
	return 0;
}