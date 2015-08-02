#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index1 = 0, index2 = 0, index3 = 0;
		vector<int> nums3(m + n, 0);

		while (index1 < m && index2 < n) {
			if (nums1[index1] < nums2[index2]) {
				nums3[index3] = nums1[index1];
				index1++;
			} else {
				nums3[index3] = nums2[index2];
				index2++;
			}
			index3++;
		}

		while (index1 < m)
			nums3[index3++] = nums1[index1++];
		while (index2 < n)
			nums3[index3++] = nums2[index2++];
		
		for (int iii = 0; iii < m + n; iii++)
			nums1[iii] = nums3[iii];
	}
};

int main()
{
	Solution sln;

{
	vector<int> nums1 = { 1, 2, 3, 7, 8, 10, 0, 0, 0, 0, 0 };
	vector<int> nums2 = { 4, 9, 22, 33, 100 };
	sln.merge(nums1, 6, nums2, nums2.size());
	print_vector(nums1);
}

	return 0;
}
