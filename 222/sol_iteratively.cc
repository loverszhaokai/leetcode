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

int get_left_height(TreeNode *node)
{
	int h = 0;

	while (node) {
		h++;
		node = node->left;
	}

	return h;
}

int get_right_height(TreeNode *node)
{
	int h = 0;

	while (node) {
		h++;
		node = node->right;
	}

	return h;
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
	int countNodes(TreeNode* root) {

		if (!root)
			return 0;

		int ans = 0;
		TreeNode *cnt_node = root;

		while (1) {

			if (!cnt_node)
				break;

			if (!cnt_node->left && !cnt_node->right) {
				ans++;
				break;
			}

			int left_left_h = get_left_height(cnt_node->left);
			int left_right_h = get_right_height(cnt_node->left);

			if (left_left_h == left_right_h) {

				ans += 1 << left_left_h;
				cnt_node = cnt_node->right;

				continue;
			}

			int right_left_h = get_left_height(cnt_node->right);
			int right_right_h = get_right_height(cnt_node->right);


			if (right_left_h == right_right_h) {

				ans += 1 << right_left_h;
				cnt_node = cnt_node->left;
			}
		}

		return ans;
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	n4.left = &n8;
	n4.right = &n9;

	n5.left = &n10;

	cout << sln.countNodes(&n1) << endl;
}

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	cout << sln.countNodes(&n1) << endl;
}


{
	TreeNode n1(1), n2(2);

	n1.left = &n2;

	cout << sln.countNodes(&n1) << endl;
}

{
	TreeNode n1(1);

	cout << sln.countNodes(&n1) << endl;
}

	return 0;
}
