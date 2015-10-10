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

// Referenece: https://leetcode.com/discuss/18330/is-it-best-solution-with-o-n-o-1

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		const int N = prices.size();

		if (N <= 1)
			return 0;

		int top[2], A[3]; 

		top[0] = top[1] = 0 - prices[0];
		A[0] = A[1] = A[2] = 0;

		for (int i = 1; i < N; i++) {

			for (int j = 1; j <= 2; j++) {

				A[j] = std::max(A[j], prices[i] + top[j - 1]);
				top[j - 1] = std::max(top[j - 1], A[j - 1] - prices[i]);
			}

		}

		return A[2];
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> prices;
		int ret;
	} test_cases [] = {

		{
			{ 1 },
			0
		},

		{
			{ 1, 2, 3 },
			2
		},

		{
			{ 1, 2, 3, 1, 8, 9, 0, 11, 15, 2, 20, 3 },
			33
		},

		{
			{ 4, 5, 3, 6, 3, 0, 5, 2, 4, 4, 8, 6, 0, 5, 7, 4, 3 },
			15
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		auto ret = sln.maxProfit(tc.prices);

		if ( tc.ret != ret ) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "Actual ret=" << ret << endl;
			return -1;
		}

	}

	return 0;
}
