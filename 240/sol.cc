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
//   RunTime: 475 ms
//   Beats  : 18.20%
//
#include <bits/stdc++.h>
#include <vector>

#include "utils.h"

using namespace std;

bool FindTarget(const vector<int>& arr, int left_index, int right_index, int target) {
  if (left_index > right_index) {
    return false;
  }
  const int mid = (left_index + right_index) / 2;
  if (arr[mid] == target) {
    return true;
  } else if (arr[mid] < target) {
    return FindTarget(arr, mid + 1, right_index, target);
  } else {
    return FindTarget(arr, left_index, mid - 1, target);
  }

  return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      for (size_t iii = 0; iii < matrix.size(); iii++) {
        const vector<int>& arr = matrix[iii];
        if (arr.front() > target) {
          break;
        }
        if (arr.back() >= target &&
            FindTarget(arr, 0, arr.size() - 1, target)) {
          return true;
        }
      }
      return false;
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
