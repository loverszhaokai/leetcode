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

		vector<vector<int>> ans;

		if (!root)
			return ans;

		TreeNode *cnt_node = root;
		TreeNode *pre_node = NULL; // The previous node of post order
		int total_val = 0;         // The total values of the nodes_vec
		vector<TreeNode *> nodes_vec;

		while (cnt_node) {
			total_val += cnt_node->val;
			nodes_vec.push_back(cnt_node);
			cnt_node = cnt_node->left;
		}

		while (nodes_vec.size() != 0) {

			cnt_node = nodes_vec.back();

			if (cnt_node->right == NULL || cnt_node->right == pre_node) {
				// Visit cnt_node

				if (!cnt_node->left && !cnt_node->right && total_val == sum) {
					// cnt_node is leaf node
					vector<int> tmp;
					for (auto item : nodes_vec)
						tmp.push_back(item->val);
					ans.push_back(tmp);
				}

				// Pop cnt_node
				total_val -= cnt_node->val;
				nodes_vec.pop_back();
				pre_node = cnt_node;
			} else {

				cnt_node = cnt_node->right;
				while (cnt_node) {
					total_val += cnt_node->val;
					nodes_vec.push_back(cnt_node);
					cnt_node = cnt_node->left;
				}
			}
		}

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
