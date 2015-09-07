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
	bool isPalindrome(int x) {

		if (x < 0)
			return false;

		// 0 <= x <= 9
		if (x < 10)
			return true;

		// x >= 10

		if (x % 10 == 0) {
			// x = 10, 100, 1000, 1233210
			return false;
		}

		int n = 0;
		while (1) {

			if (x / 10 == n) {
				// isPalindrome(x = 1234321)
				// x = 1234
				// n = 123
				return true;
			} else if (x == n) {
				return true;
			} else if (x < n) {
				return false;
			}

			n *= 10;
			n += x % 10;

			x /= 10;
		}
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		int x;
		bool ret;
	} test_cases [] = {

		{ 0, true },
		{ 9, true },
		{ 10, false },
		{ 101, true },
		{ 123, false },
		{ 12321, true },
		{ 123321, true },
		{ 12332100, false },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.isPalindrome(tc.x) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
