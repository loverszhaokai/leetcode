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

// Reference: https://leetcode.com/discuss/5198/a-o-n-2-solution-based-on-largest-rectangle-in-histogram

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		if (matrix.size() == 0 || matrix[0].size() == 0)
			return 0;

		const int c = matrix[0].size();

		vector<int> height(c + 1, 0);

		int ans = 0;

		for (int i = 0; i < matrix.size(); i++) {

			stack<int> pstk;

			for (int j = 0; j < c + 1; j++) {

				if (j != c) {
					if (matrix[i][j] == '1') {
						height[j]++;
					} else {
						height[j] = 0;
					}
				}

				if (pstk.empty() || height[j] >= height[ pstk.top() ]) {

					// height is increasing
					pstk.push(j);

				} else {

					// height is decreasing
					while (!pstk.empty() && height[j] < height[ pstk.top() ]) {
						int left_p = pstk.top();
						pstk.pop();

						int distance = pstk.empty() ? j : j - pstk.top() - 1;
						int area = height[left_p] * distance;
						ans = std::max(ans, area);
					}

					pstk.push(j);
				}
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

		{
			{
				{ '1', '0', '1', '0' },
				{ '1', '0', '1', '1' },
				{ '1', '0', '1', '1' },
				{ '1', '1', '1', '1' },
			},
			6
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
