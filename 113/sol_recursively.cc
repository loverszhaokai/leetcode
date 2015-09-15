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

int S;
int total_val;
vector<int> cnt_path;
vector<vector<int>> ans;

void preorder(TreeNode *node)
{
	if (!node)
		return;

	total_val += node->val;
	cnt_path.push_back(node->val);

	preorder(node->left);
	preorder(node->right);

	if (!node->left && !node->right && total_val == S)
		ans.push_back(cnt_path);

	total_val -= node->val;
	cnt_path.pop_back();
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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {

		S = sum;
		total_val = 0;
		cnt_path.clear();
		ans.clear();

		if (!root)
			return ans;

		preorder(root);

		return ans;
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(5), n2(4), n3(8), n4(11), n5(13), n6(4), n7(7), n8(2), n9(5), n10(1);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;

	n3.left = &n5;
	n3.right = &n6;

	n4.left = &n7;
	n4.right = &n8;

	n6.left = &n9;
	n6.right = &n10;

	vector<vector<int>> ret = sln.pathSum(&n1, 22);

	print_matrix(ret);
}

{
	TreeNode n1(5), n2(4);

	n1.left = &n2;

	vector<vector<int>> ret = sln.pathSum(&n1, 5);

	print_matrix(ret);

	ret = sln.pathSum(&n1, 9);

	print_matrix(ret);
}

{
	TreeNode n1(5);

	vector<vector<int>> ret = sln.pathSum(&n1, 5);

	print_matrix(ret);

	ret = sln.pathSum(&n1, 9);

	print_matrix(ret);
}

	return 0;
}
