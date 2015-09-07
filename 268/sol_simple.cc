#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

// Reference: https://leetcode.com/discuss/53802/c-solution-using-bit-manipulation
// We can add 0 ~ N to the nums, so the problem becomes find the number which only
// exists once

class Solution {
public:
	int missingNumber(vector<int>& nums) {

		int ans = nums.size();

		for (int iii = 0; iii < nums.size(); iii++) {
			ans ^= nums[iii];
			ans ^= iii;
		}

		return ans;
	}
};


int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int ret;
	} test_cases [] = {

		{ { 0, 1, 2, 3, 5 }, 4 },
		{ { 0, 1, 3 }, 2 },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if (tc.ret != sln.missingNumber(tc.nums)) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "expected:" << tc.ret << endl;
			cout << "actual  :" << sln.missingNumber(tc.nums) << endl;
			return -1;
		}

	}

	return 0;
}
