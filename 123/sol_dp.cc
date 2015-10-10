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

// Reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		const int N = prices.size();

		if (N <= 1)
			return 0;

		int A[3][N];

		for (int i = 0; i < N; i++)
			A[0][i] = 0;
		A[1][0] = A[2][0] = 0;

		int top[2];
		top[0] = top[1] = 0 - prices[0];

		for (int iii = 1; iii < N; iii++) {

			for (int jjj = 1; jjj <= 2; jjj++) {

				A[jjj][iii] = std::max(A[jjj][iii - 1], prices[iii] + top[jjj - 1]);

				top[jjj - 1] = std::max(top[jjj - 1], A[jjj - 1][iii] - prices[iii]);
			}

		}

		return A[2][N - 1];
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
