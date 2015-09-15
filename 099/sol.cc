/*
 * leetcode - solutions of leetcode
 * --------------------------------
 *
 * Copyright 2015 Kai Zhao <loverszhao@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 */

#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<TreeNode *> nodes;

void inorder(TreeNode *node)
{
	if (!node)
		return;

	inorder(node->left);

	nodes.push_back(node);

	inorder(node->right);
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
	void recoverTree(TreeNode* root) {

		if (!root)
			return;

		nodes.clear();

		inorder(root);

		TreeNode *node1 = NULL, *node2 = NULL;

		for (int iii = 0; iii < nodes.size(); iii++) {

			if (iii + 1 < nodes.size() &&
				nodes[iii]->val > nodes[iii + 1]->val) {

				if (node1 == NULL) {

					node1 = nodes[iii];
					if (iii + 2 < nodes.size()) {

						if (nodes[iii + 2]->val > nodes[iii]->val) {
							// 1 8 4 10
							//   ^
							node2 = nodes[iii + 1];
							break;
						}
					} else {
						// 1 8 4
						//   ^
						node2 = nodes[iii + 1];
						break;
					}
				} else {
					node2 = nodes[iii + 1];
					break;
				}
			}
		}

		if (node1 && node2) {
			int tmp = node1->val;
			node1->val = node2->val;
			node2->val = tmp;
		}
	}
};

void print_inorder(TreeNode *root)
{
	if (!root)
		return;

	print_inorder(root->left);

	cout << root->val << "  ";

	print_inorder(root->right);
}

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);

/*

		n2
	n1        n4
			n3	n5

*/

	n2.left = &n1;
	n2.right = &n4;

	n4.left = &n3;
	n4.right = &n5;

	sln.recoverTree(&n2);

	print_inorder(&n2);
}

cout << endl << endl;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);

/*

		n2
	n1        n4
			n5	n3

*/

	n2.left = &n1;
	n2.right = &n4;

	n4.left = &n3;
	n4.right = &n5;

	sln.recoverTree(&n2);

	print_inorder(&n2);
}

cout << endl << endl;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);

/*

		n2
	n3        n4
			n1	n5

*/

	n2.left = &n3;
	n2.right = &n4;

	n4.left = &n1;
	n4.right = &n5;

	sln.recoverTree(&n2);

	print_inorder(&n2);
}

cout << endl << endl;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);

/*

		n1
	n2        n4
			n3	n5

*/

	n1.left = &n2;
	n1.right = &n4;

	n4.left = &n3;
	n4.right = &n5;

	sln.recoverTree(&n1);

	print_inorder(&n1);
}

cout << endl << endl;

{
	TreeNode n1(1), n2(2), n3(3);

/*
		n2
	n3      n1

*/

	n2.left = &n3;
	n2.right = &n1;

	sln.recoverTree(&n2);

	print_inorder(&n2);
}

cout << endl << endl;

	return 0;
}
