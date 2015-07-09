#include <climits>
#include <cmath>

#include <algorithm>
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
    TreeNode* invertTree(TreeNode* root) {
        if (NULL == root)
		return NULL;
	TreeNode *p = root->left;
	root->left = root->right;
	root->right = p;

	invertTree(root->left);
	invertTree(root->right);

	return root;
    }
};

void print_tree(TreeNode *node)
{
	if (NULL == node)
		return;
	cout << "node->val=" << node->val << endl;
	cout << "node->left=" << node->left << endl;
	cout << "node->right=" << node->right << endl;

	print_tree(node->left);
	print_tree(node->right);
}

int main()
{

{
	Solution sln;
	TreeNode n1(4), n2(2), n3(7), n4(1), n5(3), n6(6), n7(9);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n3.right = &n7;

	sln.invertTree(&n1);

	print_tree(&n1);
}

	return 0;
}
