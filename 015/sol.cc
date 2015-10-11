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

vector<int> A(3);
vector<vector<int>> ret;

void run_2sum(vector<int> &nums, int index)
{
	const int target = 0 - A[0];

	int start = index;
	int end = nums.size() - 1;

	if (start >= end)
		return;

	const int min_sum = nums[start] + nums[start + 1];

	if (min_sum > target)
		return;

	const int max_sum = nums[end] + nums[end - 1];

	if (max_sum < target)
		return;

	int sum;
	while (start < end) {

		sum = nums[start] + nums[end];

		if (sum < target)
			start++;
		else if (sum > target)
			end--;
		else {

			A[1] = nums[start];
			A[2] = nums[end];
			ret.push_back(A);

			while (start < end) {
				start++;
				if (nums[start] != nums[start - 1])
					break;
			}
		}
	}
}

void run_3sum(vector<int> &nums)
{
	for (int i = 0; i < nums.size(); i++) {

		A[0] = nums[i];
		run_2sum(nums, i + 1);

		// Skip the same values
		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}

}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		std::sort(nums.begin(), nums.end());

		ret.clear();

		run_3sum(nums);

		return ret;
	}
};
 
int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		vector<vector<int>> ret;
	} test_cases [] = {

		{
			{ -4, -1, -1, 0, 1, 2 },
			{
				{ -1, -1, 2 },
				{ -1, 0, 1 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.threeSum(tc.nums);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
