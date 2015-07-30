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
	int trap(vector<int>& height) {
		if (height.size() <= 2)
			return 0;

		int ans = 0;
		int left_index = 0;
		int right_index = height.size() - 1;
		int lower, level = 0;

		while (left_index < right_index) {
			lower = height[left_index] > height[right_index] ?
				height[right_index--]: height[left_index++];
			if (lower > level)
				level = lower;
			ans += level - lower;
		}

		return ans;
	}
};

int main()
{
	Solution sln;

{
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout << sln.trap(height) << endl;
}

{
	vector<int> height = {1,2,1};
	cout << sln.trap(height) << endl;
}

{
	vector<int> height = {1,2,1,3};
	cout << sln.trap(height) << endl;
}

{
	vector<int> height = {2,0,2};
	cout << sln.trap(height) << endl;
}

	return 0;
}
