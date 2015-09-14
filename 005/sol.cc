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

// Reference: https://leetcode.com/discuss/40559/accepted-4ms-c-solution

class Solution {
public:
	string longestPalindrome(string s) {

		int max_len = 0;
		int start = 0;
		int len, left, right;
		int iii = 0;

		while (iii < s.size()) {

			if (s.size() - iii <= max_len / 2) {
				// There can not be a larger len
				break;
			}

			len = 1;
			left = iii - 1;

			while (iii < s.size() - 1 && s[iii] == s[iii + 1]) {
				iii++;
				len++;
			}

			right = iii + 1;

			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				len += 2;
				left--;
				right++;
			}

			if (len > max_len) {
				max_len = len;
				start = left + 1;
			}

			iii++;
		}

		return s.substr(start, max_len);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		string str;
		string ret;
	} test_cases [] = {

		{ "", "" },
		{ "s", "s" },
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
