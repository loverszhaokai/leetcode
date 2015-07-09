// Reference: https://leetcode.com/discuss/44401/c%23-binary-search-approach-with-recursion-easy-to-understand

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

vector<int> arr;

// Return -1 if there is no peak element from start to end
int run_recursively(int start, int end)
{
	const int middle = (start + end) / 2;

	if (middle - 1 >= 0 && middle + 1 < arr.size() && arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1])
		return middle;
	if (middle + 1 < arr.size() && arr[middle + 1] > arr[middle])
		return run_recursively(middle + 1, end);
	else if (middle - 1 >= 0 && arr[middle - 1] > arr[middle])
		return run_recursively(start, middle - 1);
	return middle;
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
	arr = nums;
	return run_recursively(0, nums.size() - 1);
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
