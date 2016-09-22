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

//
// Details:
//   RunTime: 409ms
//   Beats  : 20.06%
//
#include <bits/stdc++.h>
#include <vector>

#include "utils.h"

using namespace std;

bool FindTarget(const vector<vector<int>>& matrix, int x_1, int y_1, int x_2, int y_2, int target) {
  if (x_1 > x_2 || y_1 > y_2 ||
      matrix[x_1][y_1] > target || matrix[x_2][y_2] < target) {
    return false;
  }

  int x = x_1, y = y_1;
  while (true) {

    if (matrix[x][y] == target) {
      return true;
    } else if (matrix[x][y] > target) {
      return FindTarget(matrix, x_1, y, x, y_2, target) || FindTarget(matrix, x, y_1, x_2, y, target);
    }

    if (x == x_2 || y == y_2) {
      break;
    }

    x++;
    y++;
  }

  if (x == x_2) {
    return FindTarget(matrix, x_1, y + 1, x_2, y_2, target);
  } else if (y == y_2) {
    return FindTarget(matrix, x + 1, y_1, x_2, y_2, target);
  }

  return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.size() == 0 || matrix[0].size() == 0) {
        return false;
      }
      return FindTarget(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);
    }
};

int main()
{
	Solution sln;

	struct TestCase {
    vector<vector<int>> matrix;
    int target;
    bool expected_ret;
	} test_cases [] = {

		{
      {
        { 1, 3, 6 },
        { 4, 6, 7 },
        { 5, 8, 9 },
      },
      6, true
    },

    {
      {
        { 1, 3, 6 },
        { 4, 6, 7 },
        { 5, 8, 9 },
      },
      2, false
    },

    {
      {
        { 1, 3, 6 },
        { 4, 6, 7 },
        { 5, 8, 9 },
      },
      5, true
    },

    {
      {
        { 1, 3, 6, 10 },
        { 4, 6, 7, 12 },
        { 5, 8, 9, 13 },
      },
      5, true
    },

    {
      {
        { 1, 3, 6, 10 },
        { 4, 6, 7, 12 },
        { 5, 8, 9, 13 },
      },
      11, false
    },

    {
      {
        { 1, 3, 6, 10 },
        { 4, 6, 7, 12 },
        { 5, 8, 9, 13 },
      },
      12, true
    },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.searchMatrix(tc.matrix, tc.target);

		if ( tc.expected_ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
