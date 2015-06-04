#include <cmath>

#include <iostream>
#include <map>
#include <string>
#include <vector>

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

// Return height of subtree
// Return -1 if subtree is not balanced
int GetHeight(TreeNode *root)
{
	if (NULL == root)
		return 0;
	const int left_height = GetHeight(root->left);
	const int right_height = GetHeight(root->right);

	if (-1 == left_height || -1 == right_height ||
		left_height < right_height - 1 || left_height > right_height + 1)
		return -1;
	return 1 + std::max(left_height, right_height);
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
    bool isBalanced(TreeNode* root) {
        const int height = GetHeight(root);
	return -1 != height;
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

	n4.left = &n6;
	n4.right = &n7;

	cout << sln.isBalanced(&n1) << endl;
}

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	cout << sln.isBalanced(&n1) << endl;
}


	return 0;
}
