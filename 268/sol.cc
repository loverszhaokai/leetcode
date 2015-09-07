#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {

		int N = nums.size() + 1;

		// bits[iii] = 0 when there are even '1' in iii-th bit
		// bits[iii] = 1 when there are odd  '1' in iii-th bit
		int bits[33];
		int nums_bits[33];
		int pow2[33];

		for (int iii = 0; iii <= 32; iii++) {
			pow2[iii] = (int)pow(2.0, iii);
			bits[iii] = 0;
			nums_bits[iii] = 0;
		}

		int n, r;

		// Calulate there are odd or even '1' in each bit
		for (int iii = 1; iii <= 32; iii++) {

			if (N <= pow2[iii - 1])
				break;

			n = N / pow2[iii];
			n *= pow2[iii - 1];

			r = N % pow2[iii];
			r -= pow2[iii - 1];
			if (r < 0)
				r = 0;

			bits[iii] = (n % 2 + r % 2) % 2;
		}

		for (int iii = 0; iii < nums.size(); iii++) {

			int k = 1;
			int c = 1;

			while (c <= 32) {

				if (k & nums[iii])
					nums_bits[c]++;

				k <<= 1;
				c++;
			}
		}

		int A = 0, B = 0;

		for (int iii = 32; iii >= 1; iii--) {
			nums_bits[iii] %= 2;

// cout << "nums_bits[" << iii << "] = " << nums_bits[iii] << endl;
// cout << "bits     [" << iii << "] = " << bits[iii] << endl;

			if (nums_bits[iii] == 1)
				A |= 1;

			if (bits[iii] == 1)
				B |= 1;

			if (iii == 1)
				break;

			A <<= 1;
			B <<= 1;
		}

		return A ^ B;
	}
};


int main()
{
	Solution sln;

	struct TestCase {
		vector<int> nums;
		int ret;
	} test_cases [] = {

		{ { 0, 1, 2, 3, 5 }, 4 },
		{ { 0, 1, 3 }, 2 },

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if (tc.ret != sln.missingNumber(tc.nums)) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "expected:" << tc.ret << endl;
			cout << "actual  :" << sln.missingNumber(tc.nums) << endl;
			return -1;
		}

	}

	return 0;
}
