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

vector<int> preorder_g;
vector<int> inorder_g;

TreeNode * solve(const int pre_left, const int pre_right, const int in_left, const int in_right)
{
	if (pre_left > pre_right)
		return NULL;

	int in_mid;

	for (in_mid = in_left; in_mid <= in_right; in_mid++) {
		if (inorder_g[in_mid] == preorder_g[pre_left])
			break;
	}

	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));

	root->val = preorder_g[pre_left];
	root->left = solve(pre_left + 1, pre_left + in_mid - in_left, in_left, in_mid - 1);
	root->right = solve(pre_left + in_mid - in_left + 1, pre_right, in_mid + 1, in_right);

	return root;
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		preorder_g = preorder;
		inorder_g = inorder;

		return solve(0, preorder_g.size() - 1, 0, inorder_g.size() - 1);
	}
};

void dfs(TreeNode *node)
{
	if (!node)
		return;

	dfs(node->left);
	dfs(node->right);

	cout << node->val << endl;
}

int main()
{
	Solution sln;

	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.left = &n6;
	n5.left = &n7;
	n5.right = &n8;
	n6.right = &n9;

	vector<int> preorder = { 1, 2, 4, 5, 7, 8, 3, 6, 9 };
	vector<int> inorder = { 4, 2, 7, 5, 8, 1, 6, 9, 3 };

	TreeNode *root = sln.buildTree(preorder, inorder);

	dfs(root);

	return 0;
}
