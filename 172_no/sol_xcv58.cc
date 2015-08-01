#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
	int trailingZeroes(int n) {
		return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
	}
};

int main()
{
	Solution sln;

	cout << sln.trailingZeroes(70) << endl;
	cout << sln.trailingZeroes(74) << endl;
	cout << sln.trailingZeroes(75) << endl;
	cout << sln.trailingZeroes(95) << endl;
	cout << sln.trailingZeroes(100) << endl;
	cout << sln.trailingZeroes(124) << endl;
	cout << sln.trailingZeroes(125) << endl;

	return 0;
}
