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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret_v;
	stack<TreeNode *> nodes_s;
	TreeNode *node = root;
	TreeNode *pre_node = NULL;

	if (NULL == root)
		return ret_v;

	while (NULL != node) {
		ret_v.push_back(node->val);
		nodes_s.push(node);
		node = node->left;
	}

	while (!nodes_s.empty()) {
		node = nodes_s.top();
		if (NULL != node->right) {
			node = node->right;
			while (NULL != node) {
				ret_v.push_back(node->val);
				nodes_s.push(node);
				node = node->left;
			}
		} else {
			nodes_s.pop();
			while (!nodes_s.empty()) {
				pre_node = nodes_s.top();
				if (pre_node->right == node) {
					nodes_s.pop();
					node = pre_node;
				} else
					break;
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
	const vector<int> vvv = sln.preorderTraversal(&n1);

	for (int iii = 0; iii < vvv.size(); iii++) {
		cout << vvv[iii] << endl;
	}

	return 0;
}
