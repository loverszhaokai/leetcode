#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret_v;
	stack<TreeNode *> nodes_s;
	TreeNode *node = root;

	while (NULL != node) {
		nodes_s.push(node);
		node = node->left;
	}

	while (!nodes_s.empty()) {
		node = nodes_s.top();
		nodes_s.pop();
		ret_v.push_back(node->val);

		if (NULL != node->right) {
			node = node->right;
			while (NULL != node) {
				nodes_s.push(node);
				node = node->left;
			}
		}
	}

	return ret_v;
    }
};

int main()
{
	TreeNode n1(1), n2(2), n3(3), n4(4);
	n1.left = &n2;
	n1.right = &n3;
	n2.right = &n4;

	Solution sln;
	const vector<int> vvv = sln.inorderTraversal(&n1);

	for (int iii = 0; iii < vvv.size(); iii++) {
		cout << vvv[iii] << endl;
	}

	return 0;
}
