#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * run_recursively(TreeNode *pnode)
{
	TreeNode *last_node = pnode;
	TreeNode *rnode = pnode->right;

	if (pnode->left) {
		last_node = run_recursively(pnode->left);
		last_node->right = rnode;
		pnode->right = pnode->left;
		pnode->left = NULL;
	}

	if (rnode)
		last_node = run_recursively(rnode);

	return last_node;
}

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
	void flatten(TreeNode* root) {
		if (!root)
			return;
		run_recursively(root);
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(5), n4(3), n5(4), n7(6);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.right = &n7;

	sln.flatten(&n1);

	TreeNode *node = &n1;

	while (node) {
		cout << node->val << endl;
		node = node->right;
	}
}

	return 0;
}
