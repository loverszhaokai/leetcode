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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
	if (0 == nums.size())
		return 0;

        int ans = nums[0];
	int sum = nums[0];

	for (int iii = 1; iii < nums.size(); iii++) {
		if (sum > 0)
			sum += nums[iii];
		else
			sum = nums[iii];
		ans = std::max(ans, sum);
	}

	return ans;
    }
};

int main()
{
	Solution sln;
	vector<int> int_v = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << sln.maxSubArray(int_v) << endl;
	return 0;
}
