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

void preorder_traverse(TreeNode *_node)
{
cout << "[preorder]" << endl;

	stack<TreeNode *> nodes;
	TreeNode *node = _node;

	while (node) {
		cout << "\t" << node->val;
		nodes.push(node);
		node = node->left;
	}

	while (!nodes.empty()) {
		node = nodes.top();
		nodes.pop();
		if (node->right) {
			node = node->right;
			while (node) {
				cout << "\t" << node->val;
				nodes.push(node);
				node = node->left;
			}
		}
	}


cout << endl;
}

void inorder_traverse(TreeNode *_node)
{
cout << "[inorder]" << endl;

	stack<TreeNode *> nodes;
	TreeNode *node = _node;

	while (node) {
		nodes.push(node);
		node = node->left;
	}

	while (!nodes.empty()) {
		node = nodes.top();
		cout << "\t" << node->val;
		nodes.pop();
		if (node->right) {
			node = node->right;
			while (node) {
				nodes.push(node);
				node = node->left;
			}
		}
	}
cout << endl;
}

void postorder_traverse(TreeNode *_node)
{
cout << "[postorder]" << endl;

	stack<TreeNode *> nodes;
	TreeNode *node = _node;
	TreeNode *last_poped_node = NULL;

	while (node) {
		nodes.push(node);
		node = node->left;
	}

	while (!nodes.empty()) {
		node = nodes.top();
		if (!node->right || node->right == last_poped_node) {
			last_poped_node = node;
			cout << "\t" << node->val;
			nodes.pop();
		} else {
			node = node->right;
			while (node) {
				nodes.push(node);
				node = node->left;
			}
		}
	}
cout << endl;
}

void postorder_traverse_map(TreeNode *_node)
{
cout << "[postorder]" << endl;

	stack<TreeNode *> nodes;
	map<TreeNode *, int> nodes_m;
	TreeNode *node = _node;

	while (node) {
		nodes.push(node);
		nodes_m[node] = 0;
		node = node->left;
	}

	while (!nodes.empty()) {
		node = nodes.top();
		if (nodes_m[node] == 0) {
			if (node->right) {
				nodes_m[node] = 1;
				node = node->right;
				while (node) {
					nodes.push(node);
					nodes_m[node] = 0;
					node = node->left;
				}
			} else {
				cout << "\t" << node->val;
				nodes.pop();
			}
		} else {
			cout << "\t" << node->val;
			nodes.pop();
		}
	}
cout << endl;
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
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;

		TreeNode *node = root;
		TreeNode *last_poped_node = NULL;
		stack<TreeNode *> nodes;
		int total_sum = 0;

		while (node) {
			total_sum += node->val;
			nodes.push(node);
			node = node->left;
		}

		while (!nodes.empty()) {
			node = nodes.top();
			if (!node->left && !node->right && sum == total_sum)
				return true;
			if (!node->right || node->right == last_poped_node) {
				last_poped_node = node;
				total_sum -= node->val;
				nodes.pop();
			} else {
				node = node->right;
				while (node) {
					total_sum += node->val;
					nodes.push(node);
					node = node->left;
				}
			}
		}
		return false;
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

	preorder_traverse(&n1);
	inorder_traverse(&n1);
	postorder_traverse(&n1);
}

{
	TreeNode n1(1), n2(2);

	n1.left = &n2;

	cout << sln.hasPathSum(&n1, 1) << endl;
	cout << sln.hasPathSum(&n1, 3) << endl;
}

{
	TreeNode n1(1);

	cout << sln.hasPathSum(&n1, 1) << endl;
}

	return 0;
}
