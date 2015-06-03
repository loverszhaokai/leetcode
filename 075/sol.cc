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
    void sortColors(vector<int>& nums) {
        int li = 0;
	int ri = 1;
	while (li < nums.size() && ri < nums.size()) {
		while (li < nums.size() && 0 == nums[li]) {
			li++;
		}

		if (ri < li)
			ri = li + 1;
		while (ri < nums.size() && 0 != nums[ri]) {
			ri++;
		}

		if (li < nums.size() && ri < nums.size()) {
			int temp = nums[li];
			nums[li] = nums[ri];
			nums[ri] = temp;
			li++;
			ri++;
		}
	}

	ri = li + 1;
	while (li < nums.size() && ri < nums.size()) {
		while (li < nums.size() && 1 == nums[li]) {
			li++;
		}

		if (ri < li)
			ri = li + 1;
		while (ri < nums.size() && 1 != nums[ri]) {
			ri++;
		}

		if (li < nums.size() && ri < nums.size()) {
			int temp = nums[li];
			nums[li] = nums[ri];
			nums[ri] = temp;
			li++;
			ri++;
		}
	}
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 1, 2, 2, 2, 2, 0, 2, 0, 1, 0, 2 };
	sln.sortColors(nums);
	for (int iii = 0; iii < nums.size(); iii++) {
		cout << nums[iii] << "  ";
	}
	cout << endl;
}

	return 0;
}
