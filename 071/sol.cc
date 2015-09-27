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

string get_next_folder(string path, int &index)
{
	string folder = "";

	if (index >= path.size())
		return folder;

	while (index < path.size()) {
		if (path[index] == '/') {
			index++;
			break;
		}

		folder += path[index++];
	}

	return folder;
}

class Solution {
public:
	string simplifyPath(string path) {

		int index = 0;
		string folder;
		stack<string> stk;

		if (path[0] == '/') {
			index++;
		}

		while (1) {

			if (index >= path.size())
				break;

			folder = get_next_folder(path, index);

			if (folder == "" || folder == ".") {
			} else if (folder == "..") {
				if (!stk.empty())
					stk.pop();
			} else {
				stk.push(folder);
			}
		}

		string ret = "";

		while (!stk.empty()) {
			ret = "/" + stk.top() + ret;
			stk.pop();
		}

		if (ret == "")
			ret = "/";

		return ret;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		string path;
		string ret;
	} test_cases [] = {

		{ "/home/", "/home" },
		{ "/a/./b/../../c/", "/c" },
		{ "/..", "/" },
		{ "/", "/" },
		{ "/c/", "/c" },
		{ "/c////", "/c" },
		{ "////", "/" },
		{ "/././.", "/" },
		{ "/a/..", "/" },
		{ "/home//foo", "/home/foo" },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		string actual_ret = sln.simplifyPath(tc.path);

		if ( tc.ret != actual_ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << actual_ret << endl;
			return -1;
		}

	}

	return 0;
}
