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

// Reference: https://leetcode.com/discuss/27198/solution-explanation-comparison-problem-easy-understand

vector<int> A(4);
vector<vector<int>> ret;

void run_2sum(vector<int> &nums, int index, int target)
{
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

			A[2] = nums[start];
			A[3] = nums[end];
			ret.push_back(A);

			const int old_val = nums[start];
			while (start < end && nums[start] == old_val)
				start++;
		}
	}
}

void run(vector<int> &nums, int index, int n, int target)
{
	if (n == 2)
		return run_2sum(nums, index, target);

	for (int i = index; i < nums.size(); i++) {

		A[n] = nums[i];
		run(nums, i + 1, n + 1, target - nums[i]);

		while (i + 1 < nums.size() && nums[i + 1] == nums[i])
			i++;
	}
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		std::sort(nums.begin(), nums.end());

		ret.clear();

		run(nums, 0, 0, target);

		return ret;
    }
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int target;
		vector<vector<int>> ret;
	} test_cases [] = {

		{
			{ 1, 0, -1, 0, -2, 2 },
			0,
			{
				{ -2, -1, 1, 2 },
				{ -2,  0, 0, 2 },
				{ -1,  0, 0, 1 },
			}
		},

		{
			{ 1, 0, -1, 0, -2, 2 },
			1,
			{
				{ -2, 0, 1, 2 },
				{ -1, 0, 0, 2 },
			}
		},

		{
			{ -3, -1, 0, 2, 4, 5 },
			2,
			{
				{ -3, -1, 2, 4 }
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.fourSum(tc.nums, tc.target);

cout << endl << endl;

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;

			print_matrix(ret);

			return -1;
		}

	}

	return 0;
}

