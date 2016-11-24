#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int x, y;

int main() {
	while (cin >> x >> y) {
		string sx = to_string(x);
		string sy = to_string(y);
		reverse(sx.begin(), sx.end());
		reverse(sy.begin(), sy.end());
		int sum = stoi(sx) + stoi(sy);
		string ssum = to_string(sum);
		reverse(ssum.begin(), ssum.end());
		cout << stoi(ssum) << endl;
	}
	return 0;
}