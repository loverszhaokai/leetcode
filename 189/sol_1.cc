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

		if (nums.size() == 0)
			return;

		const int nums_size = nums.size();

		k %= nums_size;

		if (k == 0)
			return;

		int T, old_val, new_val, cnt_pos, next_pos;

		T = 1;
		cnt_pos = 0;
		new_val = nums[cnt_pos];
		next_pos = cnt_pos;

		while (1) {

			next_pos = (next_pos + k) % nums_size;

			old_val = nums[next_pos];
			nums[next_pos] = new_val;
			new_val = old_val;

			if (next_pos == cnt_pos)
				break;
			T++;
		}

		const int c = nums_size / T - 1;

		for (int i = 1; i <= c; i++) {

			cnt_pos = i;
			new_val = nums[cnt_pos];
			next_pos = cnt_pos;

			while (1) {

				next_pos = (next_pos + k) % nums_size;

				old_val = nums[next_pos];
				nums[next_pos] = new_val;
				new_val = old_val;

				if (next_pos == cnt_pos)
					break;
			}
		}
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
