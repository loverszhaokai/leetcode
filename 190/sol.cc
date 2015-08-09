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

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t ret = 0;
		int i = 31;

		// From 1th tp 31th bit
		while (i--) {
			if (n & 1)
				ret |= 1;
			ret <<= 1;
			n >>= 1;
		}

		// The 32th bit
		if (n & 1)
			ret |= 1;

		return ret;
	}
};

int main()
{
	Solution sln;

	cout << sln.reverseBits(43261596) << endl;

	cout << sln.reverseBits(2147483648) << endl;

	return 0;
}
