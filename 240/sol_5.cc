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

// Reference: https://discuss.leetcode.com/topic/55617/clean-java-code-use-binary-search-and-divide-and-conquer
//
// Details:
//   RunTime: 315ms
//   Beats  : 25.19%
//
#include <bits/stdc++.h>
#include <vector>

#include "utils.h"

using namespace std;

bool FindTarget(const vector<vector<int>>& matrix, int row_1, int col_1, int row_2, int col_2, int target) {
  if (row_1 > row_2 || col_1 > col_2 ||
      matrix[row_1][col_1] > target || matrix[row_2][col_2] < target) {
    return false;
  }

  const int mrow = (row_1 + row_2) / 2;
  const int mcol = (col_1 + col_2) / 2;

  if (matrix[mrow][mcol] == target) {
    return true;
  } else if (matrix[mrow][mcol] < target) {
    return FindTarget(matrix, mrow + 1, col_1, row_2, col_2, target) ||
           FindTarget(matrix, row_1, mcol + 1, mrow, col_2, target);
  }
  return FindTarget(matrix, row_1, col_1, row_2, mcol - 1, target) ||
         FindTarget(matrix, row_1, mcol, mrow -1 , col_2, target);
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

    if (iii != 5) {
      continue;
    }

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
