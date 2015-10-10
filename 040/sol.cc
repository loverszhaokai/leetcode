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

vector<vector<int>> ret;
vector<int> line;
vector<int> cand;

void run(const int target, const int index)
{
	if (target == 0) {
		ret.push_back(line);
		return;
	}

	if (index >= cand.size())
		return;

	int iii = index;

	while (iii < cand.size()) {

		int cnt_val = cand[iii];
		int times = 1;

		for (int jjj = iii + 1; jjj < cand.size(); jjj++)
			if (cand[jjj] == cnt_val)
				times++;
			else
				break;

		const int next_index = iii + times;
		int kkk = 1;

		for (kkk = 1; kkk <= times; kkk++) {

			if (target < cnt_val * kkk)
				break;

			line.push_back(cnt_val);

			run(target - cnt_val * kkk, next_index);
		}

		for (int jjj = 1; jjj < kkk; jjj++)
			line.pop_back();

		iii = next_index;
	}
}

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		ret.clear();
		line.clear();

		cand = candidates;

		std::sort(cand.begin(), cand.end());

		run(target, 0);

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
			{ 10, 1, 2, 7, 6, 1, 5 },
			8,
			{
				{ 1, 2, 5 },
				{ 1, 7 },
				{ 1, 1, 6 },
				{ 2, 6 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.combinationSum2(tc.candidates, tc.target);

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
