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
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> out(nums.size(), 0);

		vector<int> prenums(nums.size(), 1);
		vector<int> postnums(nums.size(), 1);

		for (int iii = 1; iii < nums.size(); iii++) {
			prenums[iii] = nums[iii - 1] * prenums[iii - 1];
		}

		for (int iii = nums.size() - 2; iii >= 0; iii--) {
			postnums[iii] = nums[iii + 1] * postnums[iii + 1];
		}

		for (int iii = 0; iii < nums.size(); iii++) {
			out[iii] = prenums[iii] * postnums[iii];
		}

		return out;
	}
};

int main()
{
	Solution sln;

	vector<int> nums = { 1, 2, 3, 4 };
	const vector<int> ret = sln.productExceptSelf(nums);
	print_vector(ret);

	return 0;
}
