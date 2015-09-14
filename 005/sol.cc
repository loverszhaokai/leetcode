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
	string longestPalindrome(string s) {

		int len = 1;
		int start = 0, end = 0;

		int len1, len2;
		int left, right;

		if (s.size() == 0)
			return "";

		for (int iii = 0; iii < s.size(); iii++) {

			len1 = 1;
			left = iii - 1;
			right = iii + 1;

			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				len1 += 2;
				left--;
				right++;
			}

			if (len1 > len) {
				len = len1;
				start = left + 1;
				end = right - 1;
			}

			if (iii > 0 && s[iii - 1] == s[iii]) {

				len2 = 2;
				left = iii - 2;
				right = iii + 1;

				while (left >= 0 && right < s.size() && s[left] == s[right]) {
					len2 += 2;
					left--;
					right++;
				}

				if (len2 > len) {
					len = len2;
					start = left + 1;
					end = right - 1;
				}
			}
		}

		string ans(s.begin() + start, s.begin() + end + 1);

		return ans;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		string str;
		string ret;
	} test_cases [] = {

		{ "xmadamyx", "madam" },
		{ "xmaiiamyx", "maiiam" },
		{ "iiiii", "iiiii" },
		{ "iiii", "iiii" },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		const string ret = sln.longestPalindrome(tc.str);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
