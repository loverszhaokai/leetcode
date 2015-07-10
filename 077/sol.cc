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

	vector<int> v(k, 0);
	for (int iii = 0; iii < k; iii++)
		v[iii] = iii + 1;
	ans.push_back(v);

	int index;
	while (1) {
		for (index = k - 1; index >= 0; index--) {
			if (v[index] != n - k + index + 1) {
				v[index]++;
				for (int jjj = index + 1; jjj < v.size(); jjj++)
					v[jjj] = v[jjj - 1] + 1;
				ans.push_back(v);
				break;
			}
		}
		if (index < 0)
			return ans;
	}
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
