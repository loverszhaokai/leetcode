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

		TreeNode *node = root;
		TreeNode *left_last_node;

		while (node) {
			if (node->left && node->right) {
				left_last_node = node->left;

				while (left_last_node->right)
					left_last_node = left_last_node->right;

				left_last_node->right = node->right;
				node->right = node->left;
			} else if (node->left)
				node->right = node->left;

			node->left = NULL;
			node = node->right;
		}
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
