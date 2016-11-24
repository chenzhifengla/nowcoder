#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > maze;
struct Point {
	int x, y;
	Point(int x, int y) :x(x), y(y) {}
};
vector<Point> holes;

bool checkMaze(int x, int y, int n) {
	for (int i = 0; i < 9; i++) {
		if (i != y && maze[x][i] == n) return false;
		if (i != x && maze[i][y] == n) return false;
	}
	int lefttopx = x / 3 * 3;
	int lefttopy = y / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int tmpx = lefttopx + i;
			int tmpy = lefttopy + j;
			if (tmpx != x && tmpy != y && maze[tmpx][tmpy] == n) return false;
		}
	}
	return true;
}

void printMaze() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++) {
			cout << maze[i][j] << " ";
		}
		cout << maze[i][8] << endl;
	}
}

bool dfs(int level) {
	if (level >= holes.size()) {
		printMaze();
		return true;
	}
	Point p = holes[level];
	for (int n = 1; n <= 9; n++) {
		maze[p.x][p.y] = n;
		if (!checkMaze(p.x, p.y, n)) continue;
		if (dfs(level + 1)) return true;
	}
	maze[p.x][p.y] = 0;
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		vector<int> row;
		int num;
		for (int j = 0; j < 9; j++) {
			cin >> num;
			row.push_back(num);
			if (num == 0) {
				holes.emplace_back(i, j);
			}
		}
		maze.push_back(row);
	}
	dfs(0);
	return 0;
}