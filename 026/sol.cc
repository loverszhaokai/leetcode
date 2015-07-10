#include <climits>
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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	int p1 = -1;
	int p2 = -1;

	for (int iii = 1; iii < nums.size(); iii++) {
		if (nums[iii] == nums[iii - 1]) {
			p1 = iii;
			break;
		}
	}

	if (-1 == p1)
		return nums.size();

	p2 = p1 + 1;
	for (; p2 < nums.size(); p2++) {
		if (nums[p2] != nums[p2 - 1])
			break;
	}

	while (p2 < nums.size()) {
		nums[p1++] = nums[p2++];
		
		for (; p2 < nums.size(); p2++) {
			if (nums[p2] != nums[p2 - 1])
				break;
		}
	}

	while (nums.size() > p1) {
		nums.pop_back();
	}

	return p1;
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 1, 1, 1 };
	cout << sln.removeDuplicates(nums) << endl;
	print_vector(nums, 10);
}

{
	vector<int> nums = { 1, 2, 2, 2 };
	cout << sln.removeDuplicates(nums) << endl;
	print_vector(nums, 10);
}

{
	vector<int> nums = { 1, 2, 2, 2, 3, 4, 5, 5, 5 };
	cout << sln.removeDuplicates(nums) << endl;
	print_vector(nums, 10);
}

{
	vector<int> nums = { 1, 2, 2, 2, 3, 4, 5, 5, 5, 6, 7 };
	cout << sln.removeDuplicates(nums) << endl;
	print_vector(nums, 10);
}


{
	vector<int> nums = { 1, 2, 3 };
	cout << sln.removeDuplicates(nums) << endl;
	print_vector(nums, 10);
}

	return 0;
}
