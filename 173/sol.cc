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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		if (!root)
			return;
		TreeNode *node = root;
		while (node) {
			nodes.push(node);
			node = node->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !nodes.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *node = nodes.top();
		const int val = node->val;

		nodes.pop();
		if (node->right) {
			node = node->right;
			while (node) {
				nodes.push(node);
				node = node->left;
			}
		}
		return val;
	}

private:
	stack<TreeNode *> nodes;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
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

	BSTIterator i = BSTIterator(&n1);
	while (i.hasNext()) cout << i.next() << endl;
}

	return 0;
}
