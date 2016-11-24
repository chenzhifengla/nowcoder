#include <iostream>
#include <cmath>
using namespace std;

int S, R, x, y, sum, ans;

int main() {
	while (cin >> S) {
		x = 1;
		y = R = sqrt(S);
		ans = 0;
		while (x < y) {
			sum = x * x + y * y;
			if (sum > S) {
				y--;
			}
			else if (sum < S) {
				x++;
			}
			else {
				ans++;
				x++;
			}
		}
		ans *= 8;
		if (x * x * 2 == S) {
			ans += 4;
		}
		if (R * R == S) {
			ans += 4;
		}
		cout << ans << endl;
	}
	return 0;
}