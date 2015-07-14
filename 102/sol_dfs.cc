#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::queue;
using std::string;
using std::vector;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> ans;

void dfs(TreeNode *pnode, const int height)
{
	if (!pnode)
		return;
	if (ans.size() < height) {
		ans.push_back(vector<int>());
	}
	ans[height - 1].push_back(pnode->val);
	dfs(pnode->left, height + 1);
	dfs(pnode->right, height + 1);
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
    vector<vector<int>> levelOrder(TreeNode* root) {
	ans.clear();
	dfs(root, 1);
	return ans;
    }
};

int main()
{
	Solution sln;
	TreeNode n3(3), n9(9), n20(20), n15(15), n7(7);

	n3.left = &n9;
	n3.right = &n20;
	n20.left = &n15;
	n20.right = &n7;

	vector<vector<int> > ret = sln.levelOrder(&n3);
	print_matrix(ret);

	return 0;
}
