#include <iostream>
#include <vector>
using namespace std;

class Bonus {
public:
	static int getMost(vector<vector<int> > board) {
		// write code here
		vector<int> maxV = board[0];
		for (int i = 1; i < 6; i++) {
			maxV[i] += maxV[i - 1];
		}
		print(maxV);
		for (int i = 1; i < 6; i++) {
			maxV[0] += board[i][0];
			for (int j = 1; j < 6; j++) {
				maxV[j] = max(maxV[j - 1], maxV[j]) + board[i][j];
			}
			print(maxV);
		}
		return maxV[5];
	}
	static int max(int a, int b) {
		return a > b ? a : b;
	}
	static void print(vector<int> v) {
		cout << "[";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ",";
		}
		cout << "\b]" << endl;
	}
};

int main() {
	vector<vector<int> > V = {
		{426,306,641,372,477,409},
		{223,172,327,586,363,553},
		{292,645,248,316,711,295},
		{127,192,495,208,547,175},
		{131,448,178,264,207,676},
		{655,407,309,358,246,714}
	};
	cout << Bonus::getMost(V);
}