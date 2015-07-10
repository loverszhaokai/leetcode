// Reference: https://leetcode.com/discuss/43968/java-solution-with-backtracking
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

vector<vector<int>> ans;

void run_recursively(const vector<int> &_arr, const int start,
	const int end, const int count)
{
	if (0 == count) {
		ans.push_back(_arr);
		return;
	}

	for (int iii = start; iii <= end; iii++) {
		vector<int> arr = _arr;
		arr.push_back(iii);
		run_recursively(arr, iii + 1, end, count - 1);
	}
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
	ans.clear();
	run_recursively(vector<int>(), 1, n, k);
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
