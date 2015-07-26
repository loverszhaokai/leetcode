#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sum = 0;
vector<int> number;

int recursively_run(TreeNode *root)
{
    if (root)
    {
        if (root->left)
        {
            number.push_back(root->left->val);
            recursively_run(root->left);
        }
        if (root->right)
        {
            number.push_back(root->right->val);
            recursively_run(root->right);
        }
        if (!root->left && !root->right)
        {
            for (unsigned int iter = 0; iter < number.size(); iter++)
            {
                sum += number[iter] * pow(10, number.size() - iter - 1);
            }
        }

        number.pop_back();
        return sum;
    }

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
int sumNumbers(TreeNode* root) {
	if (!root)
		return 0;

	sum = 0;
	number = vector<int>(1, root->val);
	return recursively_run(root);
}
};

int main()
{
	Solution sln;

{
	TreeNode n1(0), n2(1), n3(3), n4(4), n5(5), n6(6), n7(7);

	n1.left = &n2;
	n1.right = &n3;

	// n2.left = &n4;
	// n2.right = &n5;

	// n5.left = &n6;
	// n5.right = &n7;

	cout << sln.sumNumbers(&n1) << endl;
}
	return 0;
}
