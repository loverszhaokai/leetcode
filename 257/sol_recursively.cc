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

string to_str(int n)
{
	stringstream ss;
	ss << n;

	string str;
	ss >> str;

	return str;
}

vector<string> run(TreeNode *node)
{
	vector<string> ret;
	string str = to_str(node->val);
	string str_arrow = str + "->";

	if (node->left) {
		vector<string> left = run(node->left);
		for (auto item : left)
			ret.push_back(str_arrow + item);
	}

	if (node->right) {
		vector<string> right = run(node->right);
		for (auto item : right)
			ret.push_back(str_arrow + item);
	}

	if (ret.size() == 0)
		ret.push_back(str);

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
	vector<string> binaryTreePaths(TreeNode* root) {

		vector<string> ans;

		if (!root)
			return ans;

		return run(root);
	}
};

int main()
{
	Solution sln;

	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;

	n3.left = &n5;
	n3.right = &n6;

	const vector<string> ret = sln.binaryTreePaths(&n1);

	for (auto str : ret)
		cout << str << endl;

	return 0;
}
