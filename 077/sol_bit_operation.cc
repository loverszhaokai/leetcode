// Reference: https://leetcode.com/discuss/41282/c-solution-using-bit-opration
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
    vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ans;
	if (k > n)
		return ans;
	int start = (1 << k) - 1;
	int end = 1 << n;
	int x, y;

	while (start < end) {
		int iii = 1, jjj = 1, kkk = 0;
		vector<int> v(k, 0);

		while (kkk < k) {
			if (iii & start)
				v[kkk++] = jjj;
			iii = iii << 1;
			jjj++;
		}
		ans.push_back(v);

		x = start & -start;
		y = start + x;
		start = start & ~y;
		start = start / x >> 1;
		start = start | y;
	}

	return ans;
    }
};

int main()
{
	Solution sln;

{
	vector<vector<int>> ans = sln.combine(4, 2);
	print_matrix(ans);
}

	return 0;
}

