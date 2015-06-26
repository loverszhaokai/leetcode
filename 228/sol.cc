#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::stringstream;
using std::vector;

string IntToString(const int value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
	vector<string> ret;
	if (0 == nums.size())
		return ret;

	string str;
	int left_value = nums[0];

        for (int iii = 1; iii < nums.size(); iii++) {
		if (nums[iii] != nums[iii - 1] + 1) {
			str = IntToString(left_value);
			if (left_value != nums[iii - 1]) {
				str += "->";
				str += IntToString(nums[iii - 1]);
			}
			ret.push_back(str);
			left_value = nums[iii];
		}
	}

	str = IntToString(left_value);
	if (left_value != nums.back()) {
		str += "->";
		str += IntToString(nums.back());
	}
	ret.push_back(str);

	return ret;
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 3, 4, 5, 6, 7, 9, 10, 11 };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}

{
	vector<int> nums = { 1, 3, 5, 7, 11 };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}

{
	vector<int> nums = { };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}


{
	vector<int> nums = { 112 };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}

{
	vector<int> nums = { 112, 114 };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}

{
	vector<int> nums = { 112, 113, 114 };
	vector<string> ret = sln.summaryRanges(nums);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << endl;
	}
}

	return 0;
}
