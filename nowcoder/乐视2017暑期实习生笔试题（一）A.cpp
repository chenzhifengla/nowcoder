#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, ans;
vector<string> soldiers;
string s;
vector<bool> isHas;

void dfs(int level) {
	if (level == n) {
		ans++;
		return;
	}
	string str = soldiers[level];
	for (auto it = str.cbegin(); it != str.cend(); it++) {
		if (isHas[*it - '0']) continue;
		isHas[*it - '0'] = true;
		dfs(level + 1);
		isHas[*it - '0'] = false;
	}
}

int main() {
	for (int i = 0; i < 6; i++) {
		isHas.push_back(false);
	}
	while (cin >> n) {
		ans = 0;
		soldiers.clear();
		for (auto it = isHas.begin(); it != isHas.end(); it++) {
			*it = false;
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			soldiers.push_back(s);
		}
		dfs(0);
		cout << ans << endl;
	}
}