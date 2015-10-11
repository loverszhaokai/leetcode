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

int A[3];
int ans;

int run_2sum_closest(vector<int> &nums, int target, int index, int n)
{
	int start = index;
	int end = nums.size() - 1;
	int a, b;

	while (start < end) {

		if (start == end -1) {

			a = abs(nums[start] + nums[end] - target);
			if (ans > a) {
				A[0] = n;
				A[1] = nums[start];
				A[2] = nums[end];
				ans = a;
			}
			break;
		}

		a = abs(nums[start] + nums[end] - target);
		b = abs(nums[start] + nums[end - 1] - target);

		if (a >= b) {

			if (ans > b) {
				A[0] = n;
				A[1] = nums[start];
				A[2] = nums[end - 1];
				ans = b;
			}

			end--;
		} else {

			if (ans > a) {
				A[0] = n;
				A[1] = nums[start];
				A[2] = nums[end];
				ans = a;
			}

			start++;
		}
	}

	return ans;
}

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		ans = INT_MAX;

		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 1; i++) {

			run_2sum_closest(nums, target - nums[i], i + 1, nums[i]);

			if (ans == 0)
				return target;

			// Skip the same
			while (i + 1 < nums.size() && nums[i + 1] == nums[i])
				i++;
		}

		return A[0] + A[1] + A[2];
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int target;
		int ret;
	} test_cases [] = {

		{
			{ -1, 2, 1, -4 },
			1,
			2
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.threeSumClosest(tc.nums, tc.target);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
