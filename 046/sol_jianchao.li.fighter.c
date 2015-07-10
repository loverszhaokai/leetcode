// Reference: https://leetcode.com/discuss/38255/solution-nextpermutation-permutations-without-modification

#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

bool GetNextPermutation(vector<int> &nums)
{
	if (1 >= nums.size())
		return false;
	int left_index = nums.size() - 2;
	for (; left_index >= 0; left_index--) {
		if (nums[left_index] < nums[left_index + 1])
			break;
	}
	if (-1 == left_index)
		return false;
	int right_index = nums.size() - 1;
	for (;right_index > left_index; right_index--) {
		if (nums[right_index] > nums[left_index])
			break;
	}
	std::swap(nums[left_index], nums[right_index]);
	std::reverse(nums.begin() + left_index + 1, nums.end());
	return true;
}

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
	vector<vector<int> > ret;
	vector<int> pos_v(nums.size(), 0);

	for (int iii = 0; iii < nums.size(); iii++)
		pos_v[iii] = iii;
	do {
		vector<int> new_pos_v(nums.size(), 0);
		for (int iii = 0; iii < nums.size(); iii++) {
			new_pos_v[iii] = nums[ pos_v[iii] ];
		}
		ret.push_back(new_pos_v);
	} while (GetNextPermutation(pos_v));
	return ret;
    }
};

int main()
{

	Solution sln;
{
	vector<int> nums = { 1, 2, 3, 4 };

	const vector<vector<int> > matrix = sln.permute(nums);
	print_matrix(matrix);
}

	return 0;
}
