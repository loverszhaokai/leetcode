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
    int majorityElement(vector<int>& nums) {
	int bit_32[32][2];
	for (int iii = 0; iii < 32; iii++)
	for (int jjj = 0; jjj < 2; jjj++)
		bit_32[iii][jjj] = 0;

	for (int iii = 0; iii < nums.size(); iii++) {
		for (int jjj = 0; jjj < 32; jjj++) {
			if (nums[iii] & (1 << jjj))
				bit_32[jjj][1]++;
			else
				bit_32[jjj][0]++;
		}
	}
	int ret = 0;
	for (int iii = 0; iii < 32; iii++) {
		if (bit_32[iii][1] > bit_32[iii][0])
			ret = ret | (1 << iii);
	}
	return ret;
    }
};

int main()
{
	Solution sln;
	vector<int> int_v = { 1, 2, 2 };
	cout << sln.majorityElement(int_v) << endl;
	return 0;
}
