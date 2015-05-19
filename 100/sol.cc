#include <iostream>

using std::cout;
using std::endl;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode() : val(0), left(NULL), right(NULL) {}
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
	if (NULL == p && NULL == q)        
		return true;
	if (NULL == p || NULL == q)
		return false;
	if (p->val != q->val)
		return false;
	const bool f1 = isSameTree(p->left, q->left);
	const bool f2 = isSameTree(p->right, q->right);
	if (f1 && f2)
		return true;
	return false;
    }
};

int main()
{


	TreeNode n1(1), n2(2), n3(3), n4(4);
	n1.left = &n2;
	// n1.right = &n2;

	//n3.right = &n4;



	TreeNode m1(1), m2(2), m3(3), m4(4);
	// m1.left = &m3;
	m1.right = &m2;

	// m3.right = &m4;


	Solution sln;
	cout << sln.isSameTree(&n1, &m1) << endl;

	return 0;
}
