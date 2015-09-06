#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {

		sort(citations.begin(), citations.end());

		int count = 1;

		for (int iii = citations.size() - 1; iii >= 0; iii--) {

			if (count > citations[iii]) {
				break;
			}

			count++;
		}

		return count - 1;
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
