#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m, steps, ministeps;

vector<int> getGcds() {
	vector<int> gcds;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			gcds.push_back(i);
		}
	}
	return gcds;
}


void dfs() {
	if (n > m) return ;
	else if (n == m) {
		if (steps < ministeps) {
			ministeps = steps;
		}
		return;
	}
	vector<int> gcds = getGcds();
	if (gcds.empty()) {
		return ;
	}
	else {
		for (auto it = gcds.rbegin(); it != gcds.rend(); it++) {
			steps++;
			if (steps >= ministeps) {
				steps--;
				continue;
			}
			n += *it;
			dfs();
			n -= *it;
			steps--;
		}
	}
}

int main() {
	while (cin >> n >> m) {
		steps = 0;
		ministeps = INT_MAX;
		dfs();
		if (ministeps == INT_MAX) {
			cout << "-1" << endl;
		}
		else {
			cout << ministeps << endl;
		}
	}
	return 0;
}