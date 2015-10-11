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

void run_2sum(vector<int> &nums, int target, int n_index)
{

// cout << "run_2sum(" << target << "," << n_index << ")" << endl;

	int start = n_index;
	int end = nums.size() - 1;
	int sum;

	while (start < end) {

		sum = nums[start] + nums[end];

		if (sum > target)
			end--;
		else if (sum < target)
			start++;
		else {

			A[2] = nums[start];
			A[3] = nums[end];
			ret.push_back(A);

			const int old_start_val = nums[start++];
			while (start < end && nums[start] == old_start_val)
				start++;

			const int old_end_val = nums[end--];
			while (start < end && nums[end] == old_end_val)
				end--;
		}
	}
}

void run(vector<int> &nums, int target, int n_index, int a_index)
{
	if (a_index == 2) {

		run_2sum(nums, target, n_index);

		return;
	} else if (a_index == 3) {

		for (int i = n_index; i < nums.size(); i++)
			if (nums[i] == target) {
				A[3] = target;
				ret.push_back(A);
				break;
			}
		return;
	} else if (a_index == 4) {

		if (target == 0)
			ret.push_back(A);
		return;
	}

	while (n_index < nums.size()) {

		int times = 1;
		const int cnt_val = nums[n_index];

		for (int i = n_index + 1; i < nums.size(); i++)
			if (nums[i] == cnt_val)
				times++;
			else
				break;

		const int next_index = n_index + times;
		const int need = 4 - a_index;

		for (int i = 1; i <= times && i <= need; i++) {
			A[a_index + i - 1] = cnt_val;
			run(nums, target - cnt_val * i, next_index, a_index + i);
		}

		n_index = next_index;
	}
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		std::sort(nums.begin(), nums.end());

		ret.clear();

		run(nums, target, 0, 0);

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
