#include <iostream>
using namespace std;

long long getSum(int n) {
	long long sum = 0;
	long long oddnums = (n + 1) / 2;
	sum += oddnums + oddnums * (oddnums - 1);
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		long long sum = 0;
		while (n) {
			sum += getSum(n);
			n /= 2;
		}
		cout << sum << endl;
	}
	return 0;
}