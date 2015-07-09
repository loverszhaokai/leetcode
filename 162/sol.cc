#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Is first element a peak element
	if (1 == nums.size())
		return 0;
	else if (nums[0] > nums[1])
		return 0;

	// nums.size() >= 2
	for (int iii = 1; iii < nums.size() - 1; iii++) {
		if (nums[iii] > nums[iii - 1] && nums[iii] > nums[iii + 1])
			return iii;
	}

	return nums.size() - 1;
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1 };
	cout << "ret=" << sln.findPeakElement(nums) << endl;
}

{
	vector<int> nums = { 1, 2, 3, 1 };
	cout << "ret=" << sln.findPeakElement(nums) << endl;
}

{
	vector<int> nums = { 4, 3, 2 };
	cout << "ret=" << sln.findPeakElement(nums) << endl;
}

	return 0;
}
