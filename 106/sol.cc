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

vector<int> inorder_g;
vector<int> postorder_g;

TreeNode * solve(const int in_left, const int in_right, const int post_left, const int post_right)
{
	if (post_left > post_right)
		return NULL;

	int in_mid;

	for (in_mid = in_left; in_mid <= in_right; in_mid++) {
		if (inorder_g[in_mid] == postorder_g[post_right])
			break;
	}

	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));

	root->val = postorder_g[post_right];
	root->left = solve(in_left, in_mid - 1, post_left, post_left + in_mid - in_left - 1);
	root->right = solve(in_mid + 1, in_right, post_left + in_mid - in_left, post_right - 1);

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		inorder_g = inorder;
		postorder_g = postorder;

		return solve(0, inorder_g.size() - 1, 0, postorder_g.size() - 1);
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

	vector<int> inorder   = { 4, 2, 7, 5, 8, 1, 6, 9, 3 };
	vector<int> postorder = { 4, 7, 8, 5, 2, 9, 6, 3, 1 };

	TreeNode *root = sln.buildTree(inorder, postorder);

	dfs(root);

	return 0;
}
