#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, r, avg, a, b;
long long target, sum;
long long timeAll;
struct Course {
	int a, b;
	Course(int a, int b) :a(a), b(b) {}
	bool operator < (const Course& t)const {
		return b < t.b;
	}
};
vector<Course> courses;
							
int main() {
	while (cin >> n >> r >> avg) {
		target = (long long)n * avg;
		sum = 0;
		timeAll = 0;
		courses.clear();
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			courses.emplace_back(a, b);
			sum += a;
		}
		if (sum >= target) {
			cout << 0 << endl;
			continue;
		}

		sort(courses.begin(), courses.end());
		for (auto it = courses.cbegin(); it != courses.cend(); it++) {
			long long score = r - it->a;
			if (sum + score < target) {
				sum += score;
				timeAll += score * it->b;
			}
			else {
				timeAll += (target - sum) * it->b;
				sum = target;
				break;
			}
		}
		cout << timeAll << endl;
	}
	return 0;
}