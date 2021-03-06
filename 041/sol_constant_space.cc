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
	int firstMissingPositive(vector<int>& nums) {

		int index;

		if (nums.size() == 0)
			return 1;

		for (int i = 0; i < nums.size(); i++) {

			while (1) {
				if (nums[i] > 0 && nums[i] <= nums.size()) {
					index = nums[i] - 1;

					if (i != index) {
						if (nums[index] == index + 1)
							break;
						std::swap(nums[index], nums[i]);
					} else
						break;
				} else
					break;
			}
		}

		for (int i = 0; i < nums.size(); i++)
			if (i != nums[i] - 1)
				return i + 1;

		return nums.size() + 1;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int ret;
	} test_cases [] = {

		{
			{ 1, 2, 0 },
			3
		},

		{
			{ 3, 4, -1, 1 },
			2
		},

		{
			{ 3, 4, 5, 1 },
			2
		},

		{
			{ 3, 4, 2, 1 },
			5
		},

		{
			{ -1, -2, -1 },
			1
		},

		{
			{ 1, 1 },
			2
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.firstMissingPositive(tc.nums);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
