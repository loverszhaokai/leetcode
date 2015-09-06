#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

// Reference: https://leetcode.com/discuss/53150/solution-time-space-understaning-with-simple-explanation
// The two integers are A and B.
// 1. We can get the value of A ^ B by xor all the nums
// 2. A ^ B must not be 0, so we can get the different bits of A and B
// 3. Get one different bit, which maybe A set 1 and B set 0
// 4. Group the original nums by the bit, GroupA set 1, and GroupB set 0
// 5. Now the problem is to find the num which only exsits once in GroupA and GroupB

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {

		int a_xor_b = 0;

		for (auto item: nums)
			a_xor_b ^= item;

		int diff_bit = 1;
		while (1) {
			if (a_xor_b & diff_bit)
				break;
			diff_bit <<= 1;
		}

		int A = 0;
		int B = 0;

		for (auto item: nums)
			if (item & diff_bit)
				A ^= item;
			else
				B ^= item;

		vector<int> ret(2);
		ret[0] = A;
		ret[1] = B;

		return ret;
	}
};

int main()
{
	Solution sln;

	const struct TestCase {
		vector<int> nums;
		const vector<int> ept_ret;
	} test_cases [] = {

		{
			{ 1, 2, 1, 3, 2, 5 },
			{ 3, 5 }
		},

		{
			{ 1, 2, 1, 3, 2, 5, 3, 7},
			{ 7, 5 }
		},

	};

	for (auto item : test_cases) {

		const vector<int> ret = sln.singleNumber(item.nums);
		if (ret[0] == item.ept_ret[0] && ret[1] == item.ept_ret[1]
			|| ret[1] == item.ept_ret[0] && ret[0] == item.ept_ret[1]) {
		} else {
			cout << "Failed" << endl;
			return -1;
		}
	}


	return 0;
}
