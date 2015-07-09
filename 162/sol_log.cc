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
	int ret;

	if (start >= end || end == start + 1)
		return -1;

	const int middle = (start + end) / 2;
	if (arr[middle] > arr[middle - 1] && arr[middle] > arr[middle + 1])
		return middle;

	const int k = arr[middle + 1] - arr[middle];

	if (arr[start] == arr[end]) {
		if (arr[middle] >= arr[start]) {
			if (k > 0)
				return run_recursively(middle, end);
			else
				return run_recursively(start, middle);
		} else
			goto last;
	} else if (arr[start] < arr[end]) {
		if (arr[middle] >= arr[end]) {
			if (k > 0)
				return run_recursively(middle, end);
			else
				return run_recursively(start, middle);
		} else if (arr[middle] < arr[end] && arr[middle] >= arr[start]) {
			if (k > 0)
				goto last;
			else
				return run_recursively(start, middle);
		} else {
			goto last;
		}
	} else {
		if (arr[middle] >= arr[start]) {
			if (k > 0)
				return run_recursively(middle, end);
			else
				return run_recursively(start, middle);
		} else if (arr[middle] < arr[start] && arr[middle] >= arr[end]) {
			if (k > 0)
				return run_recursively(middle, end);
			else
				goto last;
		} else {
			goto last;
		}
	}

last:
	ret = run_recursively(start, middle);
	if (-1 != ret)
		return ret;
	return run_recursively(middle, end);
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Is first element a peak element
	if (1 == nums.size())
		return 0;
	else if (nums[0] > nums[1])
		return 0;

	// Is last element a peak element
	const int last_index = nums.size() - 1;
	if (nums[last_index] > nums[last_index - 1])
		return last_index;

	arr = nums;

	return run_recursively(0, last_index);
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
