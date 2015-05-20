#include <iostream>

using std::cout;
using std::endl;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root)
		return;
	if (root->left) {
		root->left->next = root->right;
		if (root->next)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
	}
    }
};

int main()
{
	return 0;
}
