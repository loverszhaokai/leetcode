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
    int removeElement(vector<int>& nums, int val) {
        vector<int> ret;

	for (int iii = 0; iii < nums.size(); iii++) {
		if (val != nums[iii])
			ret.push_back(nums[iii]);
	}

	nums = ret;
	return ret.size();
    }
};

int main()
{
	Solution sln;
{
	vector<int> nums = { 1, 2, 3, 4, 6, 1, 2, 9, 10 };
	int ret = sln.removeElement(nums, 1);
	cout << "ret=" << ret << endl;
	for (int iii = 0; iii < nums.size(); iii++) {
		cout << nums[iii] << "  ";
	}
	cout << endl;
}

	return 0;
}
