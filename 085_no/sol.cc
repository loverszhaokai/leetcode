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

// Reference: https://leetcode.com/discuss/20240/share-my-dp-solution

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;

		const int c = matrix[0].size();

		vector<int> left(c, 0);
		vector<int> right(c, c);
		vector<int> height(c, 0);

		int ans = 0;

		for (int i = 0; i < matrix.size(); i++) {

			int cnt_left = 0;

			for (int j = 0; j < c; j++) {
				if (matrix[i][j] == '1') {
					height[j]++;
					left[j] = std::max(left[j], cnt_left);
				} else {
					height[j] = 0;
					left[j] = 0;
					cnt_left = j + 1;
				}
			}

			int cnt_right = c;

			for (int j = c - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					right[j] = std::min(right[j], cnt_right);
				} else {
					cnt_right = j;
					right[j] = c;
				}
			}

			int a = 0;
			for (int j = 0; j < c; j++) {
				a = height[j] * (right[j] - left[j]);
				ans = std::max(ans, a);
			}
		}

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<char> > matrix;
		int ret;
	} test_cases [] = {

		{
			{
				{ '1', '1', '1', '1', '1', '1' },
				{ '1', '1', '1', '1', '1', '0' },
				{ '1', '1', '1', '1', '0', '0' },
				{ '0', '1', '1', '0', '0', '0' },
				{ '0', '1', '1', '0', '0', '0' },
				{ '0', '1', '1', '0', '0', '0' },
				{ '0', '1', '1', '0', '0', '0' },
				{ '0', '1', '0', '0', '0', '0' },
			},
			14
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];
		int actual_ret = sln.maximalRectangle(tc.matrix);

		if ( tc.ret != actual_ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << actual_ret << endl;
			return -1;
		}

	}

	return 0;
}
