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

TreeNode *run(TreeNode *node, TreeNode *p, TreeNode *q,	bool *find_p, bool *find_q)
{
	if (!node)
		return NULL;

	if (node == p)
		*find_p = true;
	if (node == q)
		*find_q = true;

	TreeNode * ret = NULL;
	bool left_find_p = false, left_find_q = false;
	bool right_find_p = false, right_find_q = false;

	ret = run(node->left, p, q, &left_find_p, &left_find_q);
	if (ret)
		return ret;

	ret = run(node->right, p, q, &right_find_p, &right_find_q);
	if (ret)
		return ret;

	*find_p = *find_p || left_find_p || right_find_p;
	*find_q = *find_q || left_find_q || right_find_q;

	if (*find_p && *find_q)
		return node;
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

		if (!root || !p || !q)
			return NULL;

		if (p == q)
			return p;

		bool find_p = false, find_q = false;

		return run(root, p, q, &find_p, &find_q);
	}
};

int main()
{
	Solution sln;

	TreeNode n1(3), n2(5), n3(1), n4(6), n5(2), n6(0), n7(8), n10(7), n11(4);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	n5.left = &n10;
	n5.right = &n11;

	TreeNode *ret = sln.lowestCommonAncestor(&n1, &n2, &n11);
	cout << ret->val << endl;

	ret = sln.lowestCommonAncestor(&n1, &n2, &n6);
	cout << ret->val << endl;

	return 0;
}
