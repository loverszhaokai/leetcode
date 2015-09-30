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

vector<int> solve(const vector<int> &nums, const int left, const int right, const int target)
{
	if (left > right)
		return { -1, -1 };

	const int mid = (left + right) / 2;

	if (nums[left] == target && nums[right] == target)
		return { left, right };

	if (target < nums[left] || target > nums[right])
		return { -1, -1 };

	if (nums[mid] < target)

		return solve(nums, mid + 1, right, target);

	else if (nums[mid] == target) {

		int l, r;

		vector<int> ret1 = solve(nums, left, mid - 1, target);
		vector<int> ret2 = solve(nums, mid + 1, right, target);

		if (ret1[0] == -1)
			l = mid;
		else
			l = ret1[0];

		if (ret2[1] == -1)
			r = mid;
		else
			r = ret2[1];

		return { l, r };

	} else if (nums[mid] > target)

		return solve(nums, left, mid - 1, target);
}

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return solve(nums, 0, nums.size() - 1, target);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int target;
		vector<int> ret;
	} test_cases [] = {

		{
			{ 1, 2, 3, 3, 4, 4, 5 },
			3,
			{ 2, 3 }
		},

		{
			{ 1, 2, 3, 3, 4, 4, 5 },
			6,
			{ -1, -1 }
		},

		{
			{ 1, 3, 3, 3, 3, 4, 5 },
			3,
			{ 1, 4 }
		},

		{
			{ 3, 3, 3, 3, 3 },
			3,
			{ 0, 4 }
		},

		{
			{ 3, 3, 3, 3, 3, 4, 5, 6 },
			3,
			{ 0, 4 }
		},

		{
			{ 1, 2, 3, 3, 3, 3, 3 },
			3,
			{ 2, 6 }
		},

		{
			{ 1, 3 },
			1,
			{ 0, 0 }
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		vector<int> ret = sln.searchRange(tc.nums, tc.target);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;

			cout << ret[0] << "---" << ret[1] << endl;

			return -1;
		}

	}

	return 0;
}
