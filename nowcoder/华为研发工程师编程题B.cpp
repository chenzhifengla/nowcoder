#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;
vector<int> nums;

int main() {
	while (cin >> n) {
		nums.clear();
		for (int i = 0; i < n; i++) {
			cin >> num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		auto nend = unique(nums.begin(), nums.end());
		for (auto it = nums.begin(); it != nend; it++) {
			cout << *it << endl;
		}
	}
	return 0;
}