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
	int minimumTotal(vector<vector<int>>& triangle) {

		if (triangle.size() == 0 || triangle[0].size() == 0)
			return 0;

		if (triangle.size() == 1)
			return triangle[0][0];

		vector<int> arr = triangle.back();
		int size = arr.size();

		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < triangle[i].size(); j++) {
				arr[j] = std::min(arr[j], arr[j + 1]);
				arr[j] += triangle[i][j];
			}
		}

		return arr[0];
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<int> > triangle;
		int ret;
	} test_cases [] = {

		{
			{
				{ 2 },
				{ 3, 4 },
				{ 6, 5, 7 },
				{ 4, 1, 8, 3 },
			},
			11
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.minimumTotal(tc.triangle) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
