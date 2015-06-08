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

bool recursiveRun(TreeNode *pl, TreeNode *pr)
{
	if (NULL == pl && NULL == pr)
		return true;
	if (NULL == pl || NULL == pr)
		return false;
	if (pl->val != pr->val)
		return false;
	if (!recursiveRun(pl->left, pr->right))
		return false;
	return recursiveRun(pl->right, pr->left);
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
	return recursiveRun(root->left, root->right);
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

	cout << sln.isSymmetric(&n1) << endl;
}

{
	TreeNode n1(1), n2(2), n3(2), n4(3), n5(4), n6(4), n7(3);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;

	n3.left = &n7;

	cout << sln.isSymmetric(&n1) << endl;
}

	return 0;
}
