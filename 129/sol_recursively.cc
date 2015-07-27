#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int recursively_run(TreeNode *_node, const int _pv)
{
	const int cv = _pv * 10 + _node->val;

	if (!_node->left && !_node->right)
		return cv;

	int sum = 0;
	if (_node->left)
		sum += recursively_run(_node->left, cv);
	if (_node->right)
		sum += recursively_run(_node->right, cv);
	return sum;
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
	int sumNumbers(TreeNode* root) {
		if (NULL == root)
			return 0;

		return recursively_run(root, 0);
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n5.left = &n6;
	n5.right = &n7;

	cout << sln.sumNumbers(&n1) << endl;
}
	return 0;
}
