#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		return !(n & (n - 1));
	}
};

int main()
{
	Solution sln;

{
	cout << sln.isPowerOfTwo(3) << endl;
	cout << sln.isPowerOfTwo(8) << endl;
}

	return 0;
}
