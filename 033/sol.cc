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

int find_pindex(const vector<int> &nums, int start, int end)
{
	const int middle = (start + end) / 2;
	if (nums[middle] >= nums[0]) {
		if (middle == nums.size() - 1) {
			return middle;
		} else if (nums[middle] > nums[middle + 1]) {
			return middle;
		}
		return find_pindex(nums, middle + 1, end);
	} else {
		return find_pindex(nums, start, middle - 1);
	}
}

int find_target(const vector<int> &nums, int start, int end, int target)
{
	if (start > end || start < 0 || end > nums.size() - 1)
		return -1;
	const int middle = (start + end) / 2;
	if (nums[middle] == target) {
		return middle;
	} else if (nums[middle] > target) {
		return find_target(nums, start, middle - 1, target);
	} else if (nums[middle] < target) {
		return find_target(nums, middle + 1, end, target);
	}
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
	if (0 == nums.size())
		return -1;
	const int pindex = find_pindex(nums, 0, nums.size() - 1);
	if (target >= nums[0])
		return find_target(nums, 0, pindex, target);
	return find_target(nums, pindex + 1, nums.size() - 1, target);
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	cout << sln.search(nums, 1) << endl;
	cout << sln.search(nums, 999) << endl;
}

	return 0;
}
