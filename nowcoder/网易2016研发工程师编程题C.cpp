#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 23;
int G[maxn][maxn];
int n, m, k, x, y;

int clearMushroom() {
	int maxclear = 0;
	int max_x = -1, max_y = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int s = i; s <= i + 2; s++) {
				for (int t = j; t <= j + 2; t++) {
					if (G[s][t]) {
						sum++;
					}
				}
			}
			if (sum > maxclear) {
				maxclear = sum;
				max_x = i;
				max_y = j;
			}
		}
	}
	if (max_x < 0 || max_y < 0) return 0;
	else {
		for (int i = max_x; i <= max_x + 2; i++) {
			for (int j = max_y; j <= max_y + 2; j++) {
				if (G[i][j]) {
					G[i][j]--;
				}
			}
		}
		return maxclear;
	}
}

int main() {
	while (cin >> n >> m >> k) {
		memset(G, 0, sizeof(G));
		while (k--) {
			cin >> x >> y;
			G[x][y] ++;
		}
		int maxclear = 0;
		maxclear += clearMushroom();
		maxclear += clearMushroom();
		cout << maxclear << endl;
	}
	return 0;
}