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
    bool containsDuplicate(vector<int>& nums) {
	map<int, int> nums_count;
	for (int iii = 0; iii < nums.size(); iii++) {
		if (nums_count[ nums[iii] ])
			return true;
		nums_count[ nums[iii] ] = 1;
	}
	return false;
    }
};

int main()
{
	Solution sln;
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	cout << sln.containsDuplicate(nums) << endl;
}

{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 1, 1 };
	cout << sln.containsDuplicate(nums) << endl;
}

	return 0;
}
