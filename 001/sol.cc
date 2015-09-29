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
	vector<int> twoSum(vector<int>& nums, int target) {

		int v, a;
		vector<int> ret(2, 0);
		unordered_map<int, int> ump;

		for (int i = 0; i < nums.size(); i++) {

			v = nums[i];
			a = target - v;

			if (ump.find(a) != ump.end()) {

				ret[0] = ump[a];
				ret[1] = i + 1;
				break;

			} else {
				ump[ v ] = i + 1;
			}
		}

		return ret;
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
			{ 1, 2, 3 },
			3,
			{ 1, 2 }
		},

		{
			{ 1, 2, 3, 2, 4 },
			7,
			{ 3, 5 }
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.twoSum(tc.nums, tc.target) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
