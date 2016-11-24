#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int, int> buf;
vector<int> nums;
int n, num;

int main() {
	while (cin >> n) {
		buf.clear();
		nums.clear();
		for (int i = 0; i < n; i++) {
			cin >> num;
			nums.push_back(num);
			if (buf.find(num) == buf.end()) {
				buf[num] = 1;
			}
			else {
				buf[num]++;
			}
		}
		sort(nums.begin(), nums.end());
		int diff_min = INT_MAX;
		for (auto it = nums.begin(); it != nums.end() - 1; it++) {
			int diff = *(it + 1) - *it;
			if (diff < diff_min) {
				diff_min = diff;
			}
		}
		cout << 
	}
}