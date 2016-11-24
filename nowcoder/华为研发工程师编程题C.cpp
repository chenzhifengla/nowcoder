#include <iostream>
#include <string>
using namespace std;

string str;
long long num;

int getNum(char c) {
	return string("0123456789ABCDEF").find(c);
}

int main() {
	while (cin >> str) {
		num = 0;
		for (auto it = str.begin() + 2; it != str.end(); it++) {
			num *= 16;
			num += getNum(*it);
		}
		cout << num << endl;
	}
	return 0;
}