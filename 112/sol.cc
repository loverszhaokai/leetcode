#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		if (!root->left && !root->right)
			return sum == root->val;
		return hasPathSum(root->left, sum - root->val) ||
			hasPathSum(root->right, sum - root->val); 
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(5), n2(4), n3(8), n4(11), n6(13), n7(4), n8(7), n9(2), n13(1);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n3.left = &n6;
	n3.right = &n7;
	n4.left = &n8;
	n4.right = &n9;
	n7.right = &n13;

	cout << sln.hasPathSum(&n1, 22) << endl;
	cout << sln.hasPathSum(&n1, 20) << endl;
}

	return 0;
}
