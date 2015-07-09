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

int last_index;

int find_pindex(const vector<int> &nums, int start, int end)
{
	const int middle = (start + end) / 2;
	if (nums[middle] >= nums[0]) {
		if (middle == last_index) {
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
	if (start > end || start < 0 || end > last_index)
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
    bool search(vector<int>& nums, int target) {
	if (0 == nums.size())
		return false;
	last_index = nums.size() - 1;
	while (last_index != 0 && nums[last_index] == nums[0]) {
		last_index--;
	}
	const int pindex = find_pindex(nums, 0, last_index);
	if (target >= nums[0])
		return -1 != find_target(nums, 0, pindex, target);
	return -1 != find_target(nums, pindex + 1, last_index, target);
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

{
	vector<int> nums = { 1, 3, 1, 1, 1 };
	cout << sln.search(nums, 3) << endl;
	cout << sln.search(nums, 999) << endl;
}

	return 0;
}
