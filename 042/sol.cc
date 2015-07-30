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
		int left_val = height.front();
		int right_index = height.size() - 1;
		int right_val = height.back();

		while (left_index < right_index) {
			if (left_val == right_val) {
				// Move left_index
				// Move right_index
				while (left_index < right_index) {
					if (height[left_index] > left_val) {
						left_val = height[left_index];
						break;
					}
					if (height[right_index] > right_val) {
						right_val = height[right_index];
						break;
					}

					ans += left_val - height[left_index];
					ans += right_val - height[right_index];

					left_index++;
 					right_index--;
				}
				if (left_index == right_index && left_val > height[left_index]) {
					ans += left_val - height[left_index];
				}
			} else if (left_val < right_val) {
				// Move left_index
				while (left_index < right_index) {
					if (height[left_index] > left_val) {
						left_val = height[left_index];
						break;
					}
					ans += left_val - height[left_index];
					left_index++;
				}
			} else {
				// Move right_index
				while (left_index < right_index) {
					if (height[right_index] > right_val) {
						right_val = height[right_index];
						break;
					}
					ans += right_val - height[right_index];
					right_index--;
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
