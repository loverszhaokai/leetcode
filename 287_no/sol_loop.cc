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

// Reference: https://leetcode.com/discuss/61086/java-time-and-space-solution-similar-find-loop-in-linkedlist

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        if (nums.size() == 0)
            return 1;

        if (nums.size() <= 2)
            return nums[0];

        int low_index = nums.size();
        int high_index = nums.size();

		while (1) {
			low_index = nums[ low_index - 1 ];

			high_index = nums[ high_index - 1 ];
			high_index = nums[ high_index - 1 ];

			if (low_index == high_index)
				break;
		}

		int index = nums.size();

		while (1) {
			index = nums[ index - 1 ];
			low_index = nums[ low_index - 1 ];

			if (index == low_index) {
				break;
			}
		}

		return index;
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
			{ 3, 1, 4, 5, 3, 2 },
			3
		},

		{
			{ 1, 2, 3, 3 },
			3
		},

		{
			{ 1, 1 },
			1
		},

		{
			{ 1, 1, 1 },
			1
		},

		{
			{ 1, 2, 2 },
			2
		},
	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.findDuplicate(tc.nums);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
