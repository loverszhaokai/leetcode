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
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		int val;
		unordered_map<int, int> ump;

		if (k <= 0)
			return false;

		for (int i = 0; i < nums.size(); i++) {

			val = nums[i];

			if (ump.find(val) != ump.end()) {
				int d = i - ump[val];
				if (d <= k)
					return true;
			}

			ump[val] = i;
		}

		return false;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int k;
		bool ret;
	} test_cases [] = {

		{
			{ 3, 5, 3, 1 },
			2,
			true
		},

		{
			{ 3, 5, 3, 1 },
			1,
			false
		},

		{
			{ 3, 5, 3, 1 },
			0,
			false
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.containsNearbyDuplicate(tc.nums, tc.k);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
