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
	void rotate(vector<int>& nums, int k) {

		const vector<int> orig_nums = nums;
		const int nsize = nums.size();

		for (int i = 0; i < nums.size(); i++)
			nums[(i + k) % nsize] = orig_nums[i];
	}
};

int main()
{
	Solution sln;

	struct TestCase {

		vector<int> nums;
		int k;
		vector<int> final_nums;

	} test_cases [] = {

		{
			{ 1, 2, 3, 4, 5, 6, 7 },
			3,
			{ 5, 6, 7, 1, 2, 3, 4 },
		},

		{
			{ 1, 2, 3, 4, 5, 6, 7 },
			6,
			{ 2, 3, 4, 5, 6, 7, 1 },
		},

		{
			{ 1, 2 },
			1,
			{ 2, 1 }
		},

		{
			{ 1, 2 },
			0,
			{ 1, 2 }
		},
	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		sln.rotate(tc.nums, tc.k);

		if ( tc.final_nums != tc.nums ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
