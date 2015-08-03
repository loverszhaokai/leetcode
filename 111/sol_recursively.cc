#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::queue;
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
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		if (!root->left && !root->right)
			return 1;
		else if (root->left && root->right)
			return 1 + std::min(minDepth(root->left), minDepth(root->right));
		else if (root->left)
			return 1 + minDepth(root->left);
		else
			return 1 + minDepth(root->right);
	}
};

int main()
{
	Solution sln;


{
	TreeNode n1(8), n2(3), n3(10), n4(1), n5(6), n7(14), n10(4), n11(7), n12(13);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.right = &n7;
	n5.left = &n10;
	n5.right = &n11;
	n7.left = &n12;

	cout << sln.minDepth(&n1) << endl;
}

{
	TreeNode n1(8);

	cout << sln.minDepth(&n1) << endl;
}

	return 0;
}
