#include <iostream>
#include <queue>
using namespace std;

deque<int> Q;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		while (!Q.empty()) Q.pop_back();
		for (int i = n; i >= 1; i--) {
			Q.push_front(i);
			int num = Q.back();
			Q.pop_back();
			Q.push_front(num);
		}
		while (!Q.empty()) {
			int num = Q.front();
			Q.pop_front();
			if (!Q.empty()) {
				cout << num << " ";
			}
			else {
				cout << num << endl;
				break;
			}
		}
	}
	return 0;
}