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

		TreeNode *cnt_node = root;
		TreeNode *pre_node = NULL; // The previous node of post order
		list<TreeNode *> node_list;

		while (cnt_node) {
			node_list.push_back(cnt_node);
			cnt_node = cnt_node->left;
		}

		while (!node_list.empty()) {

			cnt_node = node_list.back();

			if (pre_node == cnt_node->right || cnt_node->right == NULL) {

				// Visit
				if (!cnt_node->left && !cnt_node->right) {
					// Leaf node
					string item;

					auto it = node_list.begin();
					while (it != node_list.end()) {
						item += to_str((*it)->val);
						it++;
						if (it != node_list.end())
							item += "->";
					}
					ans.push_back(item);
				}

				pre_node = cnt_node;
				node_list.pop_back();

			} else if (cnt_node->right) {

				// Add new nodes
				cnt_node = cnt_node->right;
				while (cnt_node) {
					node_list.push_back(cnt_node);
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
