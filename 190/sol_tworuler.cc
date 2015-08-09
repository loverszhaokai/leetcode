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
		n = (n >> 16) | (n << 16);
		n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
		n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
		n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};

int main()
{
	Solution sln;

	cout << sln.reverseBits(43261596) << endl;

	cout << sln.reverseBits(2147483648) << endl;

	return 0;
}
