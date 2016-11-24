//#include <stdio.h>
//#include <string.h>
//
//char buf[1001];
//int len;
//
//int main() {
//	while (scanf("%s", buf) != EOF) {
//		len = strlen(buf);
//		for (int i = 0; i < len - 1; i++) {
//			for (int j = 0; j < len - 1 - i; j++) {
//				if (buf[j] >= 'A' && buf[j] <= 'Z' &&
//					buf[j + 1] >= 'a' && buf[j + 1] <= 'z') {
//					char tmp = buf[j];
//					buf[j] = buf[j + 1];
//					buf[j + 1] = tmp;
//				}
//			}
//		}
//		printf("%s\n", buf);
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string buf;
vector<char> buf_v;

bool cmp_char(char a, char b) {
	if (a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z')
		return false;
	else return true;
}

int main() {
	while (cin >> buf) {
		buf_v.clear();
		for (auto i = 0; i < buf.length(); i++) {
			buf_v.push_back(buf[i]);
		}
		stable_sort(buf_v.begin(), buf_v.end(), cmp_char);
		string str(buf_v.begin(), buf_v.end());
		cout << str << endl;
	}
	return 0;
}