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
	vector<int> rightSideView(TreeNode* root) {

		vector<int> ans;
		queue<TreeNode *> fq, sq;
		TreeNode *node;

		if (root == NULL)
			return ans;

		fq.push(root);

		while (1) {

			ans.push_back(fq.back()->val);

			while (!fq.empty()) {

				node = fq.front();
				fq.pop();

				if (node->left)
					sq.push(node->left);

				if (node->right)
					sq.push(node->right);
			}

			if (sq.empty())
				break;

			while (!sq.empty()) {
				fq.push(sq.front());
				sq.pop();
			}
		}

		return ans;
	}
};

int main()
{
	Solution sln;

	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);

	n1.left = &n2;
	n1.right = &n3;

	n2.right = &n5;

	n3.right = &n4;

	struct TestCase {
		TreeNode *root;
		vector<int> ret;
	} test_cases [] = {

		{ &n1, { 1, 3, 4 } },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.rightSideView(tc.root) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
