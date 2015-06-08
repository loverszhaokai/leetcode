#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

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

bool iterativelyRun(TreeNode *root)
{
	TreeNode *lnode = root->left;
	TreeNode *rnode = root->right;

	stack<TreeNode *> lstack;
	stack<TreeNode *> rstack;

	while (lnode && rnode) {
		if (lnode->val != rnode->val)
			return false;
		lstack.push(lnode);
		rstack.push(rnode);

		lnode = lnode->left;
		rnode = rnode->right;
	}

	if (NULL != lnode || NULL != rnode)
		return false;

	while (!lstack.empty() && !rstack.empty()) {
		lnode = lstack.top();
		rnode = rstack.top();
		lstack.pop();
		rstack.pop();
		lnode = lnode->right;
		rnode = rnode->left;

		while (lnode && rnode) {
			if (lnode->val != rnode->val)
				return false;
			lstack.push(lnode);
			rstack.push(rnode);

			lnode = lnode->left;
			rnode = rnode->right;
		}

		if (NULL != lnode || NULL != rnode)
			return false;
	}
	return true;
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
    bool isSymmetric(TreeNode* root) {
        if (NULL == root)
		return true;
	return iterativelyRun(root);
    }
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(2), n4(3), n5(4), n6(4), n7(3);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	cout << sln.isSymmetric(&n1) << endl << endl;
}

{
	TreeNode n1(1), n2(2), n3(2), n4(3), n5(4), n6(4), n7(3);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;

	n3.left = &n7;

	cout << sln.isSymmetric(&n1) << endl << endl;
}

{
	TreeNode n1(1);

	cout << sln.isSymmetric(&n1) << endl;
}

	return 0;
}
