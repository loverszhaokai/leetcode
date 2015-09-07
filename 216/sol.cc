#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

// max_sum[0] = 0
// max_sum[1] = 9
// max_sum[2] = 9 + 8 = 17
// max_sum[3] = 9 + 8 + 7 = 24
// max_sum[4] = 9 + 8 + 7 + 6 = 30
// max_sum[5] = 9 + 8 + 7 + 6 + 5 = 35
// max_sum[6] = 9 + 8 + 7 + 6 + 5 + 4 = 39
// max_sum[7] = 9 + 8 + 7 + 6 + 5 + 4 + 3 = 42
// max_sum[8] = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 = 44
// max_sum[9] = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
const int max_sum[10] = {
	0, 9, 17, 24, 30, 35, 39, 42, 44, 45
};

int nums[10];
int initial_k;
vector<vector<int> > ans;


// Find k numbers which add up to a number n, and the numbers should be bigger than s 
void run(int k, int n, int s)
{
	if (s == 0)
		ans.clear();

	if (n <= s)
		return;

	if (k == 1) {

		nums[initial_k - 1] = n;

		vector<int> tmp(nums, nums + initial_k);
		ans.push_back(tmp);

		return;
	}

	int start = s + 1;
	const int child_biggest_num = max_sum[k - 1];

	if (child_biggest_num < n)
		start = max(start, n - child_biggest_num);

	const int end = 10 - k;

	for (int iii = start; iii <= end; iii++) {

		nums[initial_k - k] = iii;
		run(k - 1, n - iii, iii);

	}
}


class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {

		initial_k = k;
		run(k, n, 0);
		return ans;

	}
};

int main()
{
	Solution sln;

	struct TestCase {
		int k;
		int n;
		vector<vector<int> > ret;
	} test_cases [] = {

		{
			3, 7,   {
						{ 1, 2, 4 },
					}
		},

		{
			3, 9,   {
						{ 1, 2, 6 },
						{ 1, 3, 5 },
						{ 2, 3, 4 },
					}
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.combinationSum3(tc.k, tc.n) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
