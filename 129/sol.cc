#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int recursively_run(TreeNode *_node, vector<int> *_indexs)
{
	int sum = 0;

	if (_node->left == NULL && _node->right == NULL) {
		*_indexs = vector<int>(1, 0);
		return _node->val;
	}

	vector<int> cnt_indexs;

	if (_node->left != NULL) {
		vector<int> left_indexs;
		sum += recursively_run(_node->left, &left_indexs);
		for (int iii = 0; iii < left_indexs.size(); iii++) {
			sum += _node->val * pow(10.0, left_indexs[iii] + 1);
			cnt_indexs.push_back(left_indexs[iii] + 1);
		}
	}

	if (_node->right != NULL) {
		vector<int> right_indexs;
		sum += recursively_run(_node->right, &right_indexs);
		for (int iii = 0; iii < right_indexs.size(); iii++) {
			sum += _node->val * pow(10.0, right_indexs[iii] + 1);
			cnt_indexs.push_back(right_indexs[iii] + 1);
		}
	}

	*_indexs = cnt_indexs;
	return sum;
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
	int sumNumbers(TreeNode* root) {
		if (NULL == root)
			return 0;

		vector<int> indexs;
		return recursively_run(root, &indexs);
	}
};

int main()
{
	Solution sln;

{
	TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n5.left = &n6;
	n5.right = &n7;

	cout << sln.sumNumbers(&n1) << endl;
}
	return 0;
}
