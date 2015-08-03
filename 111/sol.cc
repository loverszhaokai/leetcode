#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::queue;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

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
	int minDepth(TreeNode* root) {
		TreeNode *node = root;

		if (!node)
			return 0;

		int count1 = 1;
		int count2 = 0;
		int height = 1;
		queue<TreeNode *> nodes;

		nodes.push(node);
		while (!nodes.empty()) {
			node = nodes.front();
			nodes.pop();

			if (!node->left && !node->right)
				break;
			if (node->left) {
				nodes.push(node->left);
				count2++;
			}
			if (node->right) {
				nodes.push(node->right);
				count2++;
			}

			if (--count1 == 0) {
				count1 = count2;
				count2 = 0;
				height++;
			}
		}
		return height;
	}
};

int main()
{
	Solution sln;


{
	TreeNode n1(8), n2(3), n3(10), n4(1), n5(6), n7(14), n10(4), n11(7), n12(13);

	n1.left = &n2;
	n1.right = &n3;
	n2.left = &n4;
	n2.right = &n5;
	n3.right = &n7;
	n5.left = &n10;
	n5.right = &n11;
	n7.left = &n12;

	cout << sln.minDepth(&n1) << endl;
}

{
	TreeNode n1(8);

	cout << sln.minDepth(&n1) << endl;
}

	return 0;
}
