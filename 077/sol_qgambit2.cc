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

// Reference: https://leetcode.com/discuss/43968/java-solution-with-backtracking
void combine_backtrack_implement(vector<vector<int> > *_matrix, vector<int> *_nums,
        const int start, const int end, const int index, const int k)
{
        if (index == k) {
                _matrix->push_back(*_nums);
                return;
        }

        for (int iii = start; iii <= end - k + index + 1; iii++) {
                (*_nums)[index] = iii;
                combine_backtrack_implement(_matrix, _nums, iii + 1, end, index + 1, k);
        }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;

        if (k > n || k <= 0)
                return ans;

        vector<int> nums(k, 0);
        combine_backtrack_implement(&ans, &nums, 1, n, 0, k);
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
