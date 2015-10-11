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
	void moveZeroes(vector<int>& nums) {

		int zero_counts = 0;

		for (int i = 0; i < nums.size(); i++) {

			if (nums[i] == 0)
				zero_counts++;
			else
				nums[i - zero_counts] = nums[i];
		}

		for (int i = nums.size() - zero_counts; i < nums.size(); i++)
			nums[i] = 0;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		vector<int> ret;
	} test_cases [] = {

		{
			{ 0, 1, 0, 3, 12 },
			{ 1, 3, 12, 0, 0 },
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		sln.moveZeroes(tc.nums);

		if ( tc.ret != tc.nums ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
