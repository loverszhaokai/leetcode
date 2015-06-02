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
        int ret = nums[0];
	for (int iii = 1; iii < nums.size(); iii++)
		ret = std::min(ret, nums[iii]);
	return ret;
    }
};

int main()
{
	Solution sln;
	vector<int> arr = { 4, 5, 6, 7, 0, 1, 2 };
	cout << sln.findMin(arr) << endl;
	return 0;
}
