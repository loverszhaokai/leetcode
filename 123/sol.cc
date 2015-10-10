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
	int maxProfit(vector<int>& prices) {

		const int N = prices.size();

		if (N <= 1)
			return 0;

		int A[N];

		A[0] = 0;

		int min_p = prices[0];
		int max_p = prices[0];
		int cnt_p;

		for (int i = 1; i < N; i++) {

			cnt_p = prices[i];

			A[i] = A[i - 1];

			if (min_p > cnt_p) {

				min_p = cnt_p;
				max_p = cnt_p;

			} else if (max_p < cnt_p) {

				max_p = cnt_p;
				A[i] = std::max(A[i - 1], max_p - min_p);
			}
		}

		int B[N];

		B[N - 1] = 0;

		min_p = prices[N - 1];
		max_p = prices[N - 1];

		for (int i = N - 2; i >= 0; i--) {

			cnt_p = prices[i];

			B[i] = B[i + 1];

			if (max_p < cnt_p) {

				max_p = cnt_p;
				min_p = cnt_p;

			} else if (min_p > cnt_p) {

				min_p = cnt_p;
				B[i] = std::max(B[i], max_p - min_p);
			}
		}

		int ans = 0;

		ans = std::max(ans, A[N - 1]);
		ans = std::max(ans, B[0]);

		for (int i = 1; i < N - 1; i++)
			ans = std::max(ans, A[i] + B[i + 1]);

		return ans;
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
