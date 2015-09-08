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


// Reference: https://leetcode.com/discuss/10254/a-simple-recursive-solution
// Create Binary Search Try -- in order

vector<TreeNode*> solve(int start, int end)
{
	vector<TreeNode *> ret;

	if (start > end) {
		ret.push_back(NULL);
		return ret;
	}

	for (int iii = start; iii <= end; iii++) {

		// Left tree is smaller than iii
		const vector<TreeNode *> left_child = solve(start, iii - 1);
		// Right tree is bigger than iii
		const vector<TreeNode *> right_child = solve(iii + 1, end);

		for (int jjj = 0; jjj < left_child.size(); jjj++) {
			for (int kkk = 0; kkk < right_child.size(); kkk++) {

				TreeNode *node = new TreeNode(iii);
				node->left = left_child[jjj];
				node->right = right_child[kkk];

				ret.push_back(node);
			}
		}
	}
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
	vector<TreeNode*> generateTrees(int n) {
		return solve(1, n);
	}
};

void print_tree(TreeNode *node)
{
	if (node == NULL) {
		cout << " #";
		return;
	}

	cout << " " << node->val << " " << endl;

	print_tree(node->left);	
	print_tree(node->right);	
}

int main()
{
	Solution sln;

	const vector<TreeNode *> ret = sln.generateTrees(4);

	for (int iii = 0; iii < ret.size(); iii++) {
		print_tree(ret[iii]);
		cout << endl;
	}

	return 0;
}

