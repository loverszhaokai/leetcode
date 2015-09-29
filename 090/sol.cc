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

int status;
int combination;
vector<int> indexs;

void init(int c)
{
	status = 1;
	combination = c;
	for (int i = 0; i < c; i++)
		indexs[i] = i;
}

int get_next_combination()
{
	if (status == 1) {
		status = 0;
		return 1;
	}

	for (int i = combination - 1; i >= 0; i--) {

		if (indexs[i] < indexs.size() - (combination - i)) {

			indexs[i]++;

			for (int j = i + 1; j < combination; j++)
				indexs[j] = indexs[j - 1] + 1;
			return 1;
		}
	}

	return 0;
}

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		vector<vector<int> > ret;

		std::sort(nums.begin(), nums.end());

		indexs = vector<int>(nums.size());

		ret.push_back(vector<int>(0));

		for (int i = 1; i <= nums.size(); i++) {

			set<vector<int> > sv;
			vector<int> line(i);

			init(i);

			while (get_next_combination()) {

				for (int j = 0; j < i; j++)
					line[j] = nums[ indexs[j] ];

				sv.insert(line);
			}

			set<vector<int> >::iterator it = sv.begin();

			while (it != sv.end()) {
				ret.push_back(*it);
				it++;
			}
		}

		return ret;
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
			{ 2, 1, 2 },
			{
				{ },

				{ 1 },
				{ 2 },

				{ 1, 2 },
				{ 2, 2 },

				{ 1, 2, 2 },
			}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.subsetsWithDup(tc.nums) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
