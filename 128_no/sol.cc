#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int ans, high, low;
		int cv;
		unordered_map<int, int> nm;

		if (nums.size() == 0)
			return 0;

		ans = 1;
		for (int iii = 0; iii < nums.size(); iii++) {
			cv = nums[iii];
			if (nm.find(cv) != nm.end())
				continue;

			nm[cv] = cv;
// cout << "nm[" << cv << "]=" << nm[cv] << endl;

			if (nm.find(cv + 1) != nm.end()) {
// cout << "nm[" << cv << "]=" << nm[cv] << endl;
				high = nm[cv + 1];
				low = cv;
				nm[high] = low;
				nm[low] = high;
				ans = std::max(ans, high - low + 1);

// cout << "\t" << low << "~~~" << high << "" << endl;
			}
			if (nm.find(cv - 1) != nm.end()) {
				high = nm[cv];
				low = nm[cv - 1];
				nm[high] = low;
				nm[low] = high;
				ans = std::max(ans, high - low + 1);

// cout << "\tnm[" << nm[cv] << "]=" << nm[nm[cv]] << endl;
// cout << "\tnm[" << nm[cv - 1] << "]=" << nm[nm[cv - 1]] << endl;
// cout << "\t" << low << "~~~" << high << "" << endl;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 100, 4, 200, 1, 3, 2 };
	cout << sln.longestConsecutive(nums) << endl;
}

{
	vector<int> nums = { 100, 4, 200, 1, 3, 2, 2, 3 };
	cout << sln.longestConsecutive(nums) << endl;
}

{
	vector<int> nums = { 100, 4, 200, 1, 3, 2, 2, 3, 3, 5, 6, 7, 8, 8, 8, 9, 2, 2 };
	cout << sln.longestConsecutive(nums) << endl;
}

{
	vector<int> nums = { 0, 0 };
	cout << sln.longestConsecutive(nums) << endl;
}

	return 0;
}
