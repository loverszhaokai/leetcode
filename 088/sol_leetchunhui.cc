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
		int index1 = m - 1, index2 = n - 1, index3 = m + n - 1;

		while (index1 >= 0 && index2 >= 0) {
			if (nums1[index1] < nums2[index2]) {
				nums1[index3--] = nums2[index2--];
			} else {
				nums1[index3--] = nums1[index1--];
			}
		}

		while (index2 >= 0)
			nums1[index3--] = nums2[index2--];
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
