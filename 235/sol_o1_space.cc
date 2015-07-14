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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *node = root;
		int pchoice, qchoice; // 0 -> left; 1 -> found; 2 -> right

		while (1) {
			if (p == node)
				pchoice = 1;
			else if (p->val < node->val)
				pchoice = 0;
			else
				pchoice = 2;

			if (q == node)
				qchoice = 1;
			else if (q->val < node->val)
				qchoice = 0;
			else
				qchoice = 2;

			if (pchoice == 1 || qchoice == 1)
				return node;
			else if (pchoice != qchoice)
				return node;
			else if (pchoice == 0)
				node = node->left;
			else
				node = node->right;
		}
	}
};

int main()
{
	Solution sln;
	TreeNode n6(6), n2(2), n8(8), n0(0), n4(4), n7(7), n9(9), n3(3), n5(5);
	
	n6.left = &n2;
	n6.right = &n8;
	n2.left = &n0;
	n2.right = &n4;
	n8.left = &n7;
	n8.right = &n9;
	n4.left = &n3;
	n4.right = &n5;

	TreeNode *node;

	node = sln.lowestCommonAncestor(&n6, &n2, &n8);
	cout << "node->val=" << node->val << endl;
	node = sln.lowestCommonAncestor(&n6, &n2, &n4);
	cout << "node->val=" << node->val << endl;
	node = sln.lowestCommonAncestor(&n6, &n3, &n5);
	cout << "node->val=" << node->val << endl;

	return 0;
}
