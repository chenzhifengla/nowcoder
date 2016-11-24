#include <iostream>
#include <string>
#include <set>
using namespace std;

string origin, ans;
set<char> S;

int main() {
	while (cin >> origin) {
		S.clear();
		ans.clear();
		for (auto it = origin.begin(); it != origin.end(); it++) {
			if (S.count(*it) == 0) {
				ans.push_back(*it);
				S.insert(*it);
			}
		}
		cout << ans << endl;
	}
	return 0;
}