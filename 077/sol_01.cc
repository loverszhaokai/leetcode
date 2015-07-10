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
	vector<vector<int> > ans;

	if (k > n || k <= 0)
		return ans;

	vector<int> v(k, 0);
	vector<int> nums(n, 0);
	for (int iii = 0; iii < k; iii++)
		nums[iii] = 1;

	int index = 0, iii = 0;
	while (1) {
		// Push the positions to the vector
		index = 0;
		iii = 0;
		while (index < k && iii < n) {
			if (nums[iii])
				v[index++] = iii + 1;
			iii++;
		}
		ans.push_back(v);

		int i10 = -1;
		for (int jjj = 0; jjj < n - 1; jjj++) {
			if (nums[jjj] == 1 && nums[jjj + 1] == 0) {
				i10 = jjj;
				break;
			}
		}

		if (-1 == i10)
			break;

		nums[i10] = 0;
		nums[i10 + 1] = 1;

		int i0 = -1; // Points to the first 0 from left to i10
		for (int jjj = 0; jjj < i10; jjj++) {
			if (0 == nums[jjj]) {
				i0 = jjj;
				break;
			}
		}
		if (-1 != i0) {
			int i1 = -1;
			for (int jjj = i10 - 1; jjj >= 0; jjj--) {
				if (1 == nums[jjj]) {
					i1 = jjj;
					break;
				}
			}
			while (i0 < i10 && i1 >= 0 && i0 < i1) {
				nums[i0] = 1;
				nums[i1] = 0;
				for (int jjj = i0; jjj < i10; jjj++) {
					if (0 == nums[jjj]) {
						i0 = jjj;
						break;
					}
				}
				for (int jjj = i1; jjj >= 0; jjj--) {
					if (1 == nums[jjj]) {
						i1 = jjj;
						break;
					}
				}
			}
		}
	}

	return ans;
    }
};

int main()
{
	Solution sln;

{
	vector<vector<int>> ans = sln.combine(25, 10);
	print_matrix(ans);
}

	return 0;
}
