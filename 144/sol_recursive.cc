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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vvv;

	if (NULL == root)
		return vvv;

	vvv.push_back(root->val);
	
	const vector<int> vl = preorderTraversal(root->left);
	const vector<int> vr = preorderTraversal(root->right);

	vvv.insert(vvv.end(), vl.begin(), vl.end());
	vvv.insert(vvv.end(), vr.begin(), vr.end());

	return vvv;
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
