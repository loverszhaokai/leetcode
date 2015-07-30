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

		int count = 0;
		for (int iii = 0; iii < 32; iii++) {
			if (n & 1) {
				count++;
				if (count > 1)
					return false;
			}
			n = n >> 1;
		}
		return count == 1;
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
