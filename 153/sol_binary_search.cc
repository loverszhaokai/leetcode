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
	int li = 0;
	int ri = nums.size() - 1;
	int mid;
	while (true) {
		if (li == ri)
			return nums[li];
		if (nums[li] < nums[ri])
			return nums[li];
		mid = (li + ri) / 2;
		if (nums[mid] >= nums[li])
			li = mid + 1;
		else
			ri = mid;
	}
    }
};

int main()
{
	Solution sln;
	vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
	cout << sln.findMin(arr) << endl;
	return 0;
}
