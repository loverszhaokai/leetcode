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

class Solution {
public:
	bool canJump(vector<int>& nums) {

		if (nums.size() == 0 || nums.size() == 1)
			return true;

		int guard_index = nums.size() - 1;
		int next_guard_index = 0;

		for (int i = guard_index - 1; i >= 0; i--) {
			if (nums[i] >= guard_index - i) {

				if (i == 0)
					return true;

				guard_index = i;
				i = guard_index;
			}
		}

		return false;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		bool ret;
	} test_cases [] = {

		{
			{ 2, 3, 1, 1, 4 },
			true
		},

		{
			{ 3, 2, 1, 0, 4 },
			false
		},

		{
			{ 1, 1, 1, 1, 0 },
			true
		},

		{
			{ 1, 0, 1, 1, 0 },
			false
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.canJump(tc.nums);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
