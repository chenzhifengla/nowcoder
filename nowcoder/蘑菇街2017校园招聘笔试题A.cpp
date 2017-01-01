#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num, mincost;
vector<int> buf[110];
int legs[110];

int main() {
	cin >> n;
	for (int i = 0; i < 110; i++) {
		buf[i].clear();
		legs[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> legs[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		buf[legs[i]].push_back(num);
	}
	for (int i = 1; i < 110; i++) {
		if (!buf[i].empty()) {
			sort(buf[i].begin(), buf[i].end());
		}
	}
	mincost = -1;
	for (int i = 109; i >= 1; i--) {
		int cost = 0;
		if (!buf[i].empty()) {
			int moreneed = 0;
			for (int j = i + 1; j < 110; j++) {
				if (!buf[j].empty()) {
					for (auto it = buf[j].cbegin(); it != buf[j].cend(); it++) {
						cost += *it;
						moreneed++;
					}
				}
			}
			int lessneed = n - buf[i].size() * 2 + 1 - moreneed;
			for (int j = 1; j < i; j++) {
				if (!buf[j].empty()) {
					for (auto it = buf[j].cbegin(); it != buf[j].cend(); it++) {
						cost += *it;
						lessneed--;
						if (lessneed == 0) break;
					}
				}
				if (lessneed == 0) break;
			}
		}
		if (mincost <= 0 || (cost > 0 && cost < mincost)) {
			mincost = cost;
		}
	}
	cout << mincost << endl;
	return 0;
}