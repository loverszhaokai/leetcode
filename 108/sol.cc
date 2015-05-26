#include <stdlib.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> nums_v;

TreeNode* run(const int left, const int right)
{
	if (left > right)
		return NULL;
	const int mid = (left + right) / 2;
	TreeNode *node = (TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = nums_v[mid];
	node->left = run(left, mid - 1);
	node->right = run(mid + 1, right);
	return node;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        nums_v = nums;
	return run(0, nums_v.size() - 1);
    }
};


int main()
{

	return 0;
}
