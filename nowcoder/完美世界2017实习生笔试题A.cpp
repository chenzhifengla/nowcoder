#include <iostream>
#include <vector>
using namespace std;
int t, n, num, max;
vector<int> nums;
vector<int> dp;
int main() {
	cin >> t;
	while (t--) {
		nums.clear();
		dp.clear();
		cin >> n;
		cin >> num;
		nums.push_back(num);
		dp.push_back(1);
		for (int i = 1; i < n; i++) {
			cin >> num;
			nums.push_back(num);
			dp.push_back(0);
			for (int j = 0; j < i; j++) {
				if (nums[j] <= nums[i] && dp[j] > dp[i]) {
					dp[i] = dp[j];
				}
			}
			dp[i]++;
		}
		max = dp[0];
		for (int i = 1; i < dp.size(); i++) {
			if (dp[i] > max) {
				max = dp[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}