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

void get_ancestors(TreeNode *root, TreeNode *dst_node, vector<TreeNode *> *_ancestors)
{
	TreeNode *node = root;

	_ancestors->clear();
	while (dst_node != node) {
		_ancestors->push_back(node);
		if (dst_node->val < node->val)
			node = node->left;
		else
			node = node->right;
	}
	_ancestors->push_back(dst_node);
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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode *> pans, qans;
		get_ancestors(root, p, &pans);
		get_ancestors(root, q, &qans);

		TreeNode *last_node;
		int index = 0;

		while (index < pans.size() && index < qans.size()) {
			if (pans[index] == qans[index])
				last_node = pans[index];
			else
				break;
			index++;
		}
		return last_node;
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

	return 0;
}
