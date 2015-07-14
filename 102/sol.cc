#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::queue;
using std::string;
using std::vector;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ans;

	if (!root)
		return ans;

	queue<TreeNode *> qnodes;
	TreeNode *node = root;
	vector<int> vnodes;
	int num, newnum;

	qnodes.push(node);
	num = 1;
	newnum = 0;

	while (!qnodes.empty()) {
		node = qnodes.front();
		qnodes.pop();

		if (node->left) {
			qnodes.push(node->left);
			newnum++;
		}
		if (node->right) {
			qnodes.push(node->right);
			newnum++;
		}

		vnodes.push_back(node->val);

		if (--num == 0) {
			num = newnum;
			newnum = 0;
			ans.push_back(vnodes);
			vnodes.clear();
		}
	}

	return ans;
    }
};

int main()
{
	Solution sln;
	TreeNode n3(3), n9(9), n20(20), n15(15), n7(7);

	n3.left = &n9;
	n3.right = &n20;
	n20.left = &n15;
	n20.right = &n7;

	vector<vector<int> > ret = sln.levelOrder(&n3);
	print_matrix(ret);

	return 0;
}
