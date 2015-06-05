#include <cmath>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

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
	if (NULL == root->left && NULL == root->right)
		return;

	TreeLinkNode *child_next = NULL;
	TreeLinkNode *root_next = root->next;
	while (root_next) {
		if (root_next->left) {
			child_next = root_next->left;
			break;
		} else if (root_next->right) {
			child_next = root_next->right;
			break;
		}
		root_next = root_next->next;
	}

	if (NULL != root->left && NULL != root->right) {
		root->left->next = root->right;
		root->right->next = child_next;
	} else if (NULL == root->left)
		root->right->next = child_next;
	else if (NULL == root->right)
		root->left->next = child_next;
	
	connect(root->right);
	connect(root->left);
    }
};

void print_tree(TreeLinkNode *node)
{
	if (NULL == node)
		return;
	cout << "node->val=" << node->val << endl;
	cout << "node->left=" << node->left << endl;
	cout << "node->right=" << node->right << endl;
	cout << "node->next=" << node->next;
	if (node->next)
		cout << "  val=" << node->next->val;
	cout << endl;
	cout << endl;

	print_tree(node->left);
	print_tree(node->right);
}

int main()
{
	Solution sln;

{
	TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n7(7);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.right = &n7;

	sln.connect(&n1);

	print_tree(&n1);	
}

{
	TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9), n10(10), n11(11), n12(12), n13(13), n14(14), n15(15);

	n1.left = &n2;
	n1.right = &n3;

	n2.left = &n4;
	n2.right = &n5;

	n3.left = &n6;
	n3.right = &n7;

	n4.left = &n8;

	n5.left = &n10;
	n5.right = &n11;

	n7.left = &n14;
	n7.right = &n15;

	sln.connect(&n1);

	print_tree(&n1);	
}

	return 0;
}
