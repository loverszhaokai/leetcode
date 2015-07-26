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
		if (nums.size() <= 1)
			return nums.size();

		int index = 1;
		int same_count = 1;
		int same_val = nums[0];
		int offset = 0;

		while (index < nums.size()) {
			if (same_val != nums[index]) {
				if (same_count > 2) {
					offset += same_count - 2;
				}
				same_count = 1;
				same_val = nums[index];
				nums[index - offset] = nums[index];
			} else {
				same_count++;
				if (same_count == 2) {
					nums[index - offset] = nums[index];
				}
			}
			index++;
		}

		if (same_count > 2) {
			offset += same_count - 2;
		}
		return index - offset;
	}
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5, 5, 6, 7, 7, 8, 9, 9 };
	int len = sln.removeDuplicates(nums);
	cout << "len=" << len << endl;
	print_vector(nums);
}
{
	vector<int> nums = { 1, 1, 1 };
	int len = sln.removeDuplicates(nums);
	cout << "len=" << len << endl;
	print_vector(nums);
}

	return 0;
}
