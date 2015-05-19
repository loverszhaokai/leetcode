#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(NULL), right(NULL) {}
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
    int maxDepth(TreeNode* root) {
	if (NULL == root)
		return 0;

        int ret = 0;

	queue<TreeNode*> qqq;
	qqq.push(root);

	TreeNode *p1 = root;

	while (!qqq.empty()) {
		const TreeNode * const node = qqq.front();
		qqq.pop();
		if (node == p1) {
			ret++;
			p1 = NULL;
		}
		if (node->left) {
			qqq.push(node->left);
			if (!p1)
				p1 = node->left;
		}
		if (node->right) {
			qqq.push(node->right);
			if (!p1)
				p1 = node->right;
		}
	}
	return ret;
    }
};


int main()
{
	TreeNode n1, n2, n3, n4, n5;

	// n1.left = &n2;
	n1.right = &n3;

	// n3.left = &n4;
	// n3.right = &n5;

	Solution sln;

	cout << sln.maxDepth(&n1) << endl;

	return 0;
}
