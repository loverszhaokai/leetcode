#include <iostream>
#include <vector>

using std::cout;
using std::endl;
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

	if (NULL == root)
		return ret_v;

	const vector<int> vl = inorderTraversal(root->left);
	ret_v.insert(ret_v.end(), vl.begin(), vl.end());
	ret_v.push_back(root->val);
	const vector<int> vr = inorderTraversal(root->right);
	ret_v.insert(ret_v.end(), vr.begin(), vr.end());

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
