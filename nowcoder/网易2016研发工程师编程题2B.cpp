#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l, num, d;
vector<int> lights;

int main() {
	while (cin >> n >> l) {
		lights.clear();
		for (int i = 0; i < n; i++) {
			cin >> num;
			lights.push_back(num);
		}
		sort(lights.begin(), lights.end());
		int maxdist = 0;
		for (auto i = 0; i < lights.size() - 1; i++) {
			if (lights[i + 1] - lights[i] > maxdist) {
				maxdist = lights[i + 1] - lights[i];
			}
		}
		if (lights.front() * 2> maxdist) {
			maxdist = lights.front() * 2;
		}
		if ((l - lights.back()) * 2 > maxdist) {
			maxdist = (l - lights.back()) * 2;
		}
		printf("%.2lf\n", (double)maxdist / 2);
	}
	return 0;
}