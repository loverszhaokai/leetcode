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

TreeNode *pre_node;
// Reference: https://leetcode.com/discuss/14886/order-traversal-please-rely-buggy-int_max-int_min-solutions
//
//       n1
//   n2      n3
// n4   n5
//
// The @pre_node is the previous node by inorder
// e.g. the @pre_node of n2 is n4
//      the @pre_node of n1 is n5
//
// Note: value of current node is bigger than its pre_node
bool run(TreeNode *node)
{
	if (node->left && !run(node->left) )
		return false;

	if (pre_node && pre_node->val >= node->val)
		return false;

	pre_node = node;

	if (node->right && !run(node->right) )
		return false;

	return true;
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
	bool isValidBST(TreeNode* root) {

		if (root == NULL)
			return true;

		pre_node = NULL;

		return run(root);
	}
};

int main()
{
	Solution sln;

	TreeNode n1(1), n2(2), n3(3), n4(4);
	TreeNode t1(1), t2(3), t3(3), t4(4);
	TreeNode m1(10), m2(5), m3(15), m4(6), m5(20);

	// n1
	//    n3
	// n2    n4
	n1.right = &n3;
	n3.left = &n2;
	n3.right = &n4;

	//    t1
	// t3   t2
	//        t4
	t1.left = &t3;
	t1.right = &t2;
	t2.right = &t4;

	//         m1
	//     m2      m3
	//           m4   m5

	m1.left = &m2;
	m1.right = &m3;
	m3.left = &m4;
	m3.right = &m5;

	struct TestCase {
		TreeNode *node;
		bool ret;
	} test_cases [] = {

		{ &n1, true },
		{ &t1, false },
		{ &m1, false },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.isValidBST(tc.node) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
