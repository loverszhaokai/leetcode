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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		vector<vector<int> > ans;

		if (!root)
			return ans;

		int height = 1;
		TreeNode *node = root;
		vector<TreeNode *> nodes;

		nodes.push_back(node);

		while (1) {

			vector<int> line(nodes.size(), 0);
			for (int i = 0; i < nodes.size(); i++)
				line[i] = nodes[i]->val;
			ans.push_back(line);

			vector<TreeNode *> nodes_next;

			for (int i = nodes.size() - 1; i >= 0; i--) {
				if (height % 2 == 0) {
					if (nodes[i]->left)
						nodes_next.push_back(nodes[i]->left);
					if (nodes[i]->right)
						nodes_next.push_back(nodes[i]->right);
				} else {
					if (nodes[i]->right)
						nodes_next.push_back(nodes[i]->right);
					if (nodes[i]->left)
						nodes_next.push_back(nodes[i]->left);
				}
			}

			nodes = nodes_next;
			if (nodes.size() == 0)
				break;

			height++;
		}

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {

	} test_cases [] = {

		{},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret !=  ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
