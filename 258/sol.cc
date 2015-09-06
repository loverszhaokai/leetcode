#include <cassert>
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

// For example:     38 =  3 * 10       + 8
// In this problem: 38 => 3 * (10 - 9) + 8 => 30 % 9 + 8 => 3 + 8
//                  11 => 1 * (10 - 9) + 1 => 10 % 9 + 1 => 1 + 1

class Solution {
public:
	int addDigits(int num) {

		if (num == 0)
			return 0;

		int ans = 0;
		
		while (num) {
			ans += num % 10;
			num /= 10;
		}

		ans %= 9;

		if (ans == 0)
			ans = 9;

		return ans;
	}
};

int main()
{
	Solution sln;

	assert(2 == sln.addDigits(38));
	assert(0 == sln.addDigits(0));

	return 0;
}
