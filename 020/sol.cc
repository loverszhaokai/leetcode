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
	bool isValid(string s) {

		if (s.size() == 0)
			return true;

		int index = 1;
		stack<char> stk;

		stk.push(s[0]);

		while (index < s.size()) {

			if (s[index] == ')') {

				if (stk.empty() || stk.top() != '(')
					return false;
				stk.pop();

			} else if (s[index] == ']') {

				if (stk.empty() || stk.top() != '[')
					return false;
				stk.pop();

			} else if (s[index] == '}') {

				if (stk.empty() || stk.top() != '{')
					return false;
				stk.pop();

			} else {

				stk.push(s[index]);

			}

			index++;
		}

		return stk.empty();
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		string s;
		bool ret;
	} test_cases [] = {

		{ "()", true },
		{ "[]", true },
		{ "{}", true },
		{ "{()()[][][()]}", true },

		{ "({()()[][][()]}", false },
		{ "()}", false },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.isValid(tc.s) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
