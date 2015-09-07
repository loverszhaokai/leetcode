#include <bits/stdc++.h>

#include "utils.h"

using namespace std;


// Reference: https://leetcode.com/discuss/55952/my-o-n-time-solution-use-java
// This solution is O(N) time which does not sort
// When there are N citations, the H-index can not bigger than N. So we can
// record the occurrence of each citations.

class Solution {
public:
	int hIndex(vector<int>& citations) {

		const int len = citations.size();

		if (len == 0)
			return 0;

		int index;
		int counts[len + 1];

		// Clear counts
		for (int iii = 0; iii < len + 1; iii++)
			counts[iii] = 0;

		// Traverse citations
		for (int iii = 0; iii < citations.size(); iii++) {

			index = citations[iii];

			if (index >= len)
				counts[len]++;
			else
				counts[index]++;
		}

		int ans = 0;

		// Find the largest H-index
		for (int iii = len; iii >= 0; iii--) {

			ans += counts[iii];

			if (ans >= iii)
				return iii;
		}

		assert(0);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<int> citations;
		int ret;
	} test_cases [] = {
		{ { 3, 3, 4, 5 }, 3 },
		{ { 3, 0, 6, 1, 5 }, 3 },
		{ { 100 }, 1 },
		{ { 4, 5, 6, 7 }, 4 },
		{ { 6, 7 }, 2 },
	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		if ( test_cases[iii].ret != sln.hIndex(test_cases[iii].citations )) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
