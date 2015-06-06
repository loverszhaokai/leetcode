#include <cmath>

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
    int findMin(vector<int>& nums) {
	int left_index = 0;
	int right_index = nums.size() - 1;
	int mid;

	while (nums[left_index] == nums[right_index] && left_index < right_index)
		right_index--;

	while (right_index >= left_index) {
		if (nums[left_index] <= nums[right_index])
			return nums[left_index];
		mid = (left_index + right_index) / 2;
		if (nums[mid] >= nums[left_index])
			left_index = mid + 1;
		else
			right_index = mid;
	}
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 4, 6, 7, 8, 1, 2, 3 };
	cout << sln.findMin(nums) << endl;
}

{
	vector<int> nums = { 7, 8, 1, 2, 3, 4, 5, 6 };
	cout << sln.findMin(nums) << endl;
}

{
	vector<int> nums = { 3, 1, 3 };
	cout << sln.findMin(nums) << endl;
}

{
	vector<int> nums = { 3, 3, 3 };
	cout << sln.findMin(nums) << endl;
}

{
	vector<int> nums = { 1, 1 };
	cout << sln.findMin(nums) << endl;
}

	return 0;
}
