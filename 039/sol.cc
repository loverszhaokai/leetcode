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

void run(vector<int>& candidates, vector<vector<int>> &ret,
	vector<int> &line, int target, int index)
{
	if (target == 0) {

		ret.push_back(line);

		return;
	}

	if (index >= candidates.size())
		return;

	int cnt_val;
	for (int i = index; i < candidates.size(); i++) {

		cnt_val = candidates[i];

		if (cnt_val > target)
			break;

		line.push_back(cnt_val);

		run(candidates, ret, line, target - cnt_val, i);

		line.pop_back();
	}
}

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		std::sort(candidates.begin(), candidates.end());

		vector<int> line;
		vector<vector<int>> ret;

		run(candidates, ret, line, target, 0);

		return ret;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> candidates;
		int target;
		vector<vector<int>> ret;
	} test_cases [] = {

		{
			{ 2, 3, 6, 7 },
			7,
			{
				{ 2, 2, 3 },
				{ 7 },
			}
		},

		{
			{ 2, 3, 6, 7 },
			9,
			{
				{ 2, 2, 2, 3 },
				{ 2, 7 },
				{ 3, 3, 3 },
				{ 3, 6 },
			}
		},

		{
			{ 8, 7, 4, 3 },
			11,
			{
				{ 3, 4, 4 },
				{ 3, 8 },
				{ 4, 7 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.combinationSum(tc.candidates, tc.target);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;

			for (int i = 0; i < ret.size(); i++) {
				for (int j = 0; j < ret[i].size(); j++) {
					cout << ret[i][j] << "  ";
				}
				cout << endl;
			}

			return -1;
		}

	}

	return 0;
}
