#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
	for (int iii = 0; iii < nums.size(); iii++) {
		if (nums[iii] >= target)
			return iii;
	}
	return nums.size();
    }
};

int main()
{
	Solution sln;

	vector<int> int_v = { 1, 3, 5, 7, 9 };

	cout << sln.searchInsert(int_v, 0) << endl;
	cout << sln.searchInsert(int_v, 1) << endl;
	cout << sln.searchInsert(int_v, 2) << endl;
	cout << sln.searchInsert(int_v, 10) << endl;

	return 0;
}
