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

// Reference: https://leetcode.com/discuss/10588/o-n-bfs-solution

class Solution {
public:
	int jump(vector<int>& nums) {

		if (nums.size() == 0 || nums.size() == 1)
			return 0;

		int from = 0;
		int to = 0;
		int ans = 0;

		while (1) {

			int index = from;
			int next_to = to;

			ans++;

			for (; index <= to; index++) {

				next_to = std::max(next_to, index + nums[index]);

				if (next_to >= nums.size() - 1)
					return ans;
			}

			from = to + 1;
			to = next_to;
		}

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int ret;
	} test_cases [] = {

		{
			{ 2, 3, 1, 1, 4 },
			2
		},

		{
			{ 99, 3, 1, 1, 4 },
			1
		},

		{
			{ 99 },
			0
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.jump(tc.nums);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
