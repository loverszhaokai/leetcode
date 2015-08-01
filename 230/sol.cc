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

int global_k;
int ans;

void recursively_run(TreeNode *node)
{
	if (global_k < 0)
		return;

	if (node->left)
		recursively_run(node->left);

	global_k--;
	if (global_k == 0)
		ans = node->val;

	if (node->right)
		recursively_run(node->right);
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
	int kthSmallest(TreeNode* root, int k) {
		global_k = k;
		recursively_run(root);
		return ans;
	}
};

int main()
{
	Solution sln;
	TreeNode n1(8), n2(3), n3(10), n4(1), n5(6), n7(14), n10(4), n11(7), n12(13);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.right = &n7;
	n5.left = &n10;
	n5.right = &n11;
	n7.left = &n12;

	cout << sln.kthSmallest(&n1, 1) << endl;
	cout << sln.kthSmallest(&n1, 4) << endl;

	return 0;
}
