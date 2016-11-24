#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return true;
}

int main() {
	vector<int> v = { 76, 43, 3, 0, 134 };
	sort(v.begin(), v.end(), cmp);
	for (auto i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}