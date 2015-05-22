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

int max3(const int i1, const int i2, const int i3)
{
	return std::max(std::max(i1, i2), i3);
}

int maxSubArrayAccrossMid(vector<int> &nums, const int left, const int right)
{
	const int mid = (left + right) / 2;
	int left_sum = nums[mid];
	int right_sum = nums[mid + 1];

	int sum = 0;
	for (int iii = mid; iii >= left; iii--) {
		sum += nums[iii];
		left_sum = std::max(left_sum, sum);
	}
	sum = 0;
	for (int iii = mid + 1; iii <= right; iii++) {
		sum += nums[iii];
		right_sum = std::max(right_sum, sum);
	}

	return left_sum + right_sum;
}

int maxSubArray1(vector<int> &nums, const int left, const int right)
{
	if (left == right)
		return nums[left];

	const int mid = (left + right) / 2;
	return max3(maxSubArray1(nums, left, mid),
			maxSubArray1(nums, mid + 1, right),
			maxSubArrayAccrossMid(nums, left, right));
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	if (0 == nums.size())
		return 0;

	return maxSubArray1(nums, 0, nums.size() - 1);
    }
};

int main()
{
	Solution sln;
	vector<int> int_v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << sln.maxSubArray(int_v) << endl;
	return 0;
}
