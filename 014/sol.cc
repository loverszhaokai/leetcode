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
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0)
			return "";

		if (strs.size() == 1)
			return strs[0];

		int pos = 0;

		while (pos < strs[0].size()) {

			for (int iii = 1; iii < strs.size(); iii++) {

				if (pos == strs[iii].size())
					goto out;

				if (strs[iii][pos] != strs[0][pos])
					goto out;
			}

			pos++;
		}

		out:
			return strs[0].substr(0, pos);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<string> strs;
		string ret;
	} test_cases [] = {

		{
			{
				"123",
				"124",
				"",
			},
			""
		},

		{
			{
			},
			""
		},

		{
			{
				"123",
				"12345",
				"1234567",
			},
			"123"
		},

		{
			{
				"",
				"",
				"123",
			},
			""
		},
	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		const string ret = sln.longestCommonPrefix(tc.strs);

		if ( tc.ret !=  ret) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
