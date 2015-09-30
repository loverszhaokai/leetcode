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

vector<int> solve(const vector<vector<int> > &matrix, const int x, int y)
{
	vector<int> ret;

	const int right_y = matrix[0].size() - y - 1;
	const int down_x = matrix.size() - x - 1;

	// right
	for (int i = y; i <= right_y; i++)
		ret.push_back(matrix[x][i]);

	// down
	for (int i = x + 1; i <= down_x; i++)
		ret.push_back(matrix[i][right_y]);

	if (down_x > x) {
		// left
		for (int i = right_y - 1; i >= y; i--)
			ret.push_back(matrix[down_x][i]);
	}

	if (right_y > y) {
		// up
		for (int i = down_x - 1; i > x; i--)
			ret.push_back(matrix[i][y]);
	}

	if (x + 1 < down_x && y + 1 < right_y) {
		vector<int> v = solve(matrix, x + 1, y + 1);
		ret.insert(ret.end(), v.begin(), v.end());
	}

	return ret;
}

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		if (matrix.size() == 0 || matrix[0].size() == 0)
			return vector<int>();

		return solve(matrix, 0, 0);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<int> > matrix;
		vector<int> ret;
	} test_cases [] = {

		{
			{
				{  1,  2,  3,  4 },
				{  5,  6,  7,  8 },
				{  9, 10, 11, 12 },
				{ 13, 14, 15, 16 },
			},
			{ 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10 }
		},
		{
			{
				{  1,  2,  3,  4 },
			},
			{ 1, 2, 3, 4 }
		},
		{
			{
				{ 1 },
				{ 2 },
			},
			{ 1, 2 }
		},

		{
			{
				{ 2, 5, 8 },
				{ 1, 2, 3 },
			},
			{ 2, 5, 8, 3, 2, 1 }
		},

		{
			{
				{  1,  2,  3, 4 },
				{ 12, 13, 14, 5 },
				{ 11, 16, 15, 6 },
				{ 10,  9,  8, 7 },
			},
			{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		vector<int> ret = sln.spiralOrder(tc.matrix);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;

			for (int i = 0; i < ret.size(); i++)
				cout << ret[i] << "  ";
			cout << endl;

			return -1;
		}

	}

	return 0;
}
