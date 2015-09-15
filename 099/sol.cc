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


TreeNode *pre_node, *node1, *node2;

void inorder(TreeNode *node)
{
	if (!node)
		return;

	inorder(node->left);

	if (pre_node) {

		if (pre_node->val > node->val) {

			if (node1 == NULL) {
				// original: 1 2 3
				// swapped : 1 3 2

				node1 = pre_node;
				node2 = node;

			} else {
				// Over
				node2 = node;
				return;
			}
		}
	}
	pre_node = node;

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

		pre_node = NULL;
		node1 = NULL;
		node2 = NULL;

		inorder(root);

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
