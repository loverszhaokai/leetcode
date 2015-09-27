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

int solve(TreeNode *node, int &max_val)
{
	int ret = 0;
	int s = 0;
	int left_ret = 0;
	int right_ret = 0;
	int left_max_val = 0;
	int right_max_val = 0;

	max_val = node->val;

	if (node->left && node->right) {

		left_ret = solve(node->left, left_max_val);
		right_ret = solve(node->right, right_max_val);

		const int mv = std::max(left_max_val, right_max_val);
		if (mv > 0)
			max_val += mv;

		s = node->val;
		if (left_max_val > 0)
			s += left_max_val;
		if (right_max_val > 0)
			s += right_max_val;

		ret = std::max(left_ret, right_ret);
		ret = std::max(ret, s);

	} else if (node->left) {

		left_ret = solve(node->left, left_max_val);

		s = node->val;
		if (left_max_val > 0) {
			s += left_max_val;
			max_val += left_max_val;
		}

		ret = std::max(left_ret, s);

	} else if (node->right) {

		right_ret = solve(node->right, right_max_val);

		s = node->val;
		if (right_max_val > 0) {
			s += right_max_val;
			max_val += right_max_val;
		}

		ret = std::max(right_ret, s);

	} else {

		ret = node->val;
	}

	return ret;
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
	int maxPathSum(TreeNode* root) {

		if (!root)
			return 0;

		int max_val;
		return solve(root, max_val);
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(3);

	n1.left = &n2;
	n1.right = &n3;

	cout << sln.maxPathSum(&n1) << endl;
}

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;

	n5.left = &n7;
	n5.right = &n8;

	n6.right = &n9;

	cout << sln.maxPathSum(&n1) << endl;
}

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(97), n8(98), n9(9);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;

	n5.left = &n7;
	n5.right = &n8;

	n6.right = &n9;

	cout << sln.maxPathSum(&n1) << endl;
}

{
	TreeNode n1(-1), n2(-2), n3(-3);

	n1.left = &n2;
	n1.right = &n3;

	cout << sln.maxPathSum(&n1) << endl;
}

{
	TreeNode n1(-2), n2(-1), n3(-3);

	n1.left = &n2;
	n1.right = &n3;

	cout << sln.maxPathSum(&n1) << endl;
}

{
	TreeNode n1(-1), n2(5), n3(4), n4(2), n5(-4);

	n1.left = &n2;

	n2.left = &n3;

	n3.right = &n4;

	n4.left = &n5;

	cout << sln.maxPathSum(&n1) << endl;
}

	return 0;
}
