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

	while (1) {
		bool finish = true;
		for (int iii = 0; iii < v.size(); iii++) {
			if (v[iii] != n - k + iii + 1) {
				finish = false;
				break;
			}
		}
		if (finish) {
			return ans;
		}

		for (int iii = v.size() - 1; iii >= 0; iii--) {
			if (v[iii] != n - k + iii + 1) {
				v[iii]++;
				for (int jjj = iii + 1; jjj < v.size(); jjj++) {
					v[jjj] = v[jjj - 1] + 1;
				}
				ans.push_back(v);
				break;
			}
		}

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
