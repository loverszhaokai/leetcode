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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
	queue<TreeNode *> q1, q2;
	TreeNode *node;

	if (!root)
		return ans;
	
	q1.push(root);
	while (1) {
		vector<int> vi1, vi2;
		while (!q1.empty()) {
			node = q1.front();
			vi1.push_back(node->val);
			q1.pop();
			if (node->left)
				q2.push(node->left);
			if (node->right)
				q2.push(node->right);
		}

		while (!q2.empty()) {
			node = q2.front();
			vi2.push_back(node->val);
			q2.pop();
			if (node->left)
				q1.push(node->left);
			if (node->right)
				q1.push(node->right);
		}
		if (!vi1.empty())
			ans.push_back(vi1);
		if (!vi2.empty())
			ans.push_back(vi2);
		if (q1.empty() && q2.empty())
			break;
	}

	std::reverse(ans.begin(), ans.end());

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

	vector<vector<int> > ret = sln.levelOrderBottom(&n3);
	print_matrix(ret);

	return 0;
}
