#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GrayCode {
public:
	vector<string> getGray(int n) {
		// write code here
		vector<string> ans;
		if (n == 1) {
			ans = { "0", "1" };
		}
		else {
			vector<string> v = getGray(n - 1);
			for (auto it = v.begin(); it != v.end(); it++) {
				ans.push_back(string("0") + *it);
			}
			for (auto it = v.rbegin(); it != v.rend(); it++) {
				ans.push_back(string("1") + *it);
			}
		}
		return ans;
	}
};