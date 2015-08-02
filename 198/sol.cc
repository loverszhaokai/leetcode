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
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		else if (nums.size() == 1)
			return nums[0];

		int tmp;
		int p2 = nums[0];
		int p1 = nums[1];
		if (p1 < p2)
			p1 = p2;

		for (int iii = 2; iii < nums.size(); iii++) {
			if (nums[iii] + p2 > p1) {
				tmp = p2;
				p2 = p1;
				p1 = nums[iii] + tmp;
			} else {
				p2 = p1;
			}
		}

		return p1;
	}
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 100, 1, 2, 200, 300, 400, 9, 8, 100, 3, 700, 900 };
	cout << sln.rob(nums) << endl;
}

{
	vector<int> nums = { 100, 1, 900 };
	cout << sln.rob(nums) << endl;
}

{
	vector<int> nums = { 1, 100, 900 };
	cout << sln.rob(nums) << endl;
}

	return 0;
}
