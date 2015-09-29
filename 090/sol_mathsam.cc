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
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		vector<vector<int> > ret;

		std::sort(nums.begin(), nums.end());

		ret.push_back(vector<int>(0));

		for (int i = 0; i < nums.size(); ) {

			int counts = 0;
			while (counts + i < nums.size() && nums[ counts + i ] == nums[i])
				counts++;

			const int size = ret.size();

			for (int j = 0; j < size; j++) {

				vector<int> tmp = ret[j];

				for (int k = 0; k < counts; k++) {
					tmp.push_back(nums[i]);
					ret.push_back(tmp);
				}
			}

			i += counts;
		}

		return ret;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		vector<vector<int> > ret;
	} test_cases [] = {

		{
			{ 2, 1, 2 },
			{
				{ },

				{ 1 },
				{ 2 },

				{ 2, 2 },

				{ 1, 2 },
				{ 1, 2, 2 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.subsetsWithDup(tc.nums) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
