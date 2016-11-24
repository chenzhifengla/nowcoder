#include <iostream>
using namespace std;

class GoUpstairs {
public:
	static int countWays(int n) {
		// write code here
		if (n < 3) return 1;
		long long ans1 = 1, ans2 = 1;
		for (int i = 3; i <= n; i++) {
			ans2 += ans1;
			ans1 = ans2 - ans1;
			ans2 %= 1000000007;
			cout << "count(" << i << ")=" << ans2 << endl;
		}
		return ans2 ;
	}
};

int main() {
	cout << GoUpstairs::countWays(96) << endl;
	return 0;
}