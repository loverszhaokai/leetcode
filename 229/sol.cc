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

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
	
	if (nums.size() < 2)
		return nums;

	int candidate1, candidate2;

	int count1 = 0;
	int count2 = 0;
	int nindex = 0;

	candidate1 = nums[0];

	for (; nindex < nums.size(); nindex++) {
		if (candidate1 != nums[nindex]) {
			count1 = nindex;
			candidate2 = nums[nindex];
			count2 = 1;
			break;
		}
	}

	if (nindex == nums.size()) {
		ret.push_back(candidate1);
		return ret;
	}

	nindex++;
	for (; nindex < nums.size(); nindex++) {
		if (candidate1 == nums[nindex]) {
			count1++;
		} else if (candidate2 == nums[nindex]) {
			count2++;
		} else {
			if (count1 && count2) {
				count1--;
				count2--;
			} else if (0 == count1) {
				count1 = 1;
				candidate1 = nums[nindex];
			} else if (0 == count2) {
				count2 = 1;
				candidate2 = nums[nindex];
			}
		}
	}

	count1 = 0;
	count2 = 0;
	nindex = 0;

	for (; nindex < nums.size(); nindex++) {
		if (candidate1 == nums[nindex])
			count1++;
		else if (candidate2 == nums[nindex])
			count2++;
	}

	if (count1 > nums.size() / 3)
		ret.push_back(candidate1);
	if (count2 > nums.size() / 3)
		ret.push_back(candidate2);

	return ret;
    }
};

void print(const vector<int> &nums)
{
	for (int iii = 0; iii < nums.size(); iii++) {
		printf("nums[%d]=%d ", iii, nums[iii]);
		if (0 == (iii + 1) % 10)
			printf("\n");
	}
	printf("\n");

}

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 2 };
	const vector<int> ret = sln.majorityElement(nums);
	print(ret);
}

{
	vector<int> nums = { 1, 2, 3, 3, 5, 3, 7 };
	const vector<int> ret = sln.majorityElement(nums);
	print(ret);
}

{
	vector<int> nums = { 1, 1 };
	const vector<int> ret = sln.majorityElement(nums);
	print(ret);
}

{
	vector<int> nums = { 1, 1, 1, 3, 3, 2, 2, 2 };
	const vector<int> ret = sln.majorityElement(nums);
	print(ret);
}

	return 0;
}
