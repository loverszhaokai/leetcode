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
	int largestRectangleArea(vector<int>& height) {

		int ans = 0;
		stack<int> stk;
		int cnt_h;

		height.push_back(0);

		for (int i = 0; i < height.size(); i++) {

			cnt_h = height[i];

			if (stk.empty() || cnt_h >= height[ stk.top() ]) {

				// height is increasing
				stk.push(i);

			} else {

				// height is decreasing
				while (!stk.empty() && cnt_h < height[ stk.top() ]) {

					int pos = stk.top();
					stk.pop();

					int h = height[pos];
					int distance;

					if (stk.empty())
						distance = i;
					else
						distance = i - stk.top() - 1;

					int a = h * distance;
					ans = std::max(ans, a);
				}

				stk.push(i);
			}
		}

		height.pop_back();

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> height;
		int ret;
	} test_cases [] = {

		{
			{ 2, 1, 5, 6, 2, 3 },
			10
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.largestRectangleArea(tc.height) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
