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
		int m;

		if (n < 5)
			return 0;

		for (int iii = 5; iii <= n; iii += 5) {
			if (iii % 10 == 0) {
				m = iii;
				while (m % 10 == 0) {
					count++;
					m /= 10;
				}
			} else if (iii % 5 == 0) {
				m = iii;
				while (m % 5 == 0) {
					count++;
					m /= 5;
				}
			}
		}
		return count;
	}
};

int main()
{
	Solution sln;

	cout << sln.trailingZeroes(10) << endl;
	cout << sln.trailingZeroes(50) << endl;
	cout << sln.trailingZeroes(500000000) << endl;
	cout << sln.trailingZeroes(2000000000) << endl;

	return 0;
}
