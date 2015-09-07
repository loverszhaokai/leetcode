#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

class Solution {
public:
	bool isUgly(int num) {

		if (num <= 0)
			return false;

		while (num % 2 == 0)
			num /= 2;

		while (num % 3 == 0)
			num /= 3;

		while (num % 5 == 0)
			num /= 5;

		if (num == 1)
			return true;
		return false;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		int num;
		bool ret;
	} test_cases [] = {

		{-1, false },  // Not ugly
		{ 0, false },  // Not ugly
		{ 1, true },
		{ 2, true },
		{ 3, true },
		{ 4, true },
		{ 5, true },
		{ 6, true },
		{ 7, false },  // Not ugly
		{ 8, true },
		{ 9, true },
		{ 10, true },
		{ 11, false }, // Not ugly
		{ 12, true },
		{ 13, false }, // Not ugly
		{ 14, false }, // Not ugly

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if (tc.ret != sln.isUgly(tc.num)) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
