#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Tree {
public:
	TreeNode *maxNode, *minNode;
	int max_val, min_val;
	vector<int> max_trace, min_trace, trace;
	int getDis(TreeNode* root) {
		// write code here
		maxNode = minNode = NULL;
		max_trace.clear();
		min_trace.clear();
		trace.clear();
		if (root) traverseTree(root);
		int same = 0;
		auto itmin = min_trace.begin();
		auto itmax = max_trace.begin();
		for (; itmin != min_trace.end() &&
			itmax != max_trace.end() &&
			*itmin == *itmax;
			itmin++, itmax++, same);
		return min_trace.size() + max_trace.size() - 2 * same;
	}

	void traverseTree(TreeNode* root) {
		trace.push_back(root->val);
		if (!maxNode || root->val > max_val) {
			max_val = root->val;
			maxNode = root;
			max_trace = trace;
		}
		if (!minNode || root->val < min_val) {
			min_val = root->val;
			minNode = root;
			min_trace = trace;
		}
		if (root->left) traverseTree(root->left);
		if (root->right) traverseTree(root->right);
	}
};

int main() {
	Tree();
	TreeNode
}