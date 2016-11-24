#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 101;
int t, n, k, num;
int nums[maxn * 2];
int nums2[maxn * 2];

int main() {
	freopen("inputA.txt", "r", stdin);
	freopen("outputA.txt", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(nums, 0, sizeof(nums));
		for (int i = 0; i < n * 2; i++) {
			cin >> nums[i];
		}
		memset(nums2, 0, sizeof(nums2));
		for (int i = 0; i < n * 2; i++) {
			int index = i;
			for (int j = 0; j < k; j++) {
				index *= 2;
				index = (index - 1) % (n * 2 - 1) + 1;
			}
			nums2[index] = nums[i];
		}
		for (int i = 0; i < n * 2 - 1; i++) {
			cout << nums2[i] << " ";
		}
		cout << nums2[n * 2 - 1] << endl;
	}
	return 0;
}