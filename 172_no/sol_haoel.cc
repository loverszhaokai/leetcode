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
		int count = 0;
		while (n) {
			count += n / 5;
			n /= 5;
		}
		return count;
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
