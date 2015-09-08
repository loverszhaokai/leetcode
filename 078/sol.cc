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

vector<int> arr;
vector<int> A;
vector<vector<int> > ans;

void solve(int index, int n, int s)
{
	if (n == 0) {
		ans.push_back(vector<int>(A.begin(), A.begin() + index));
		return;
	}

	const int end = arr.size() - n;

	for (int iii = s; iii <= end; iii++) {
		A[index] = arr[iii];
		solve(index + 1, n - 1, iii + 1);
	}
}

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {

		ans.clear();

		sort(nums.begin(), nums.end());

		arr = nums;
		A = nums;

		for (int iii = 0; iii <= nums.size(); iii++)
			solve(0, iii, 0);

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		vector<vector<int> > ret;
	} test_cases [] = {

		{ 
			{ 1, 2, 3 },
			{ 
				{ },
				{ 1 },
				{ 2 },
				{ 3 },
				{ 1, 2 },
				{ 1, 3 },
				{ 2, 3 },
				{ 1, 2, 3 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.subsets(tc.nums) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
