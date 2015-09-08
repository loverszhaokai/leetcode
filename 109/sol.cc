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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nums;

TreeNode* solve(int start, int end)
{
	if (start > end)
		return NULL;

	int middle = (start + end) / 2;
	TreeNode *node = new TreeNode(nums[middle]);

	node->left = solve(start, middle - 1);
	node->right = solve(middle + 1, end);

	return node;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	TreeNode* sortedListToBST(ListNode* head) {

		if (head == NULL)
			return NULL;

		nums.clear();
		while (head) {
			nums.push_back(head->val);
			head = head->next;
		}

		return solve(0, nums.size() - 1);
	}
};

void dfs(TreeNode *node)
{
	if (node == NULL)
		return;

	cout << node->val << endl;

	dfs(node->left);
	dfs(node->right);
}

int main()
{
	Solution sln;

	ListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);

	n1.next = &n2; n2.next = &n3;
	n3.next = &n4; n4.next = &n5;
	n5.next = &n6; n6.next = &n7;
	n7.next = &n8;

	TreeNode *root = sln.sortedListToBST(&n1);
	dfs(root);

	return 0;
}
