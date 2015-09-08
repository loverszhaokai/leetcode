/*
 * leetcode - solutions of leetcode
 * --------------------------------
 *
 * Copyright 2015 Kai Zhao <loverszhao@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 */

#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

// Reference: https://leetcode.com/discuss/9213/my-solution-using-bit-manipulation
//
// e.g. nums = { 1, 2, 3, 4 }
// end = 2^4 = 16 = 1 0000
//
// 0 0 0 0  { }
// 0 0 0 1  { 1 }
// 0 0 1 0  { 2 }
// 0 0 1 1  { 1, 2 }
// 0 1 0 0  { 3 }
// ...

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<vector<int> > ans;
		const int end = pow(2, nums.size());

		sort(nums.begin(), nums.end());

		for (int iii = 0; iii < end; iii++) {

			vector<int> A;
			int v = iii;

			for (int jjj = 0; jjj < nums.size(); jjj++) {
				if (v & 1)
					A.push_back(nums[jjj]);
				v >>= 1;
			}

			ans.push_back(A);
		}

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		vector<vector<int> > ret;
	} test_cases [] = {

		{ 
			{ 1, 2, 3 },
			{ 
				{ },
				{ 1 },
				{ 2 },
				{ 1, 2 },
				{ 3 },
				{ 1, 3 },
				{ 2, 3 },
				{ 1, 2, 3 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.subsets(tc.nums) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
