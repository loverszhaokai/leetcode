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
    int singleNumber(vector<int>& nums) {
	int ttt;
	int bit_32[32] = { 0 };
	for (int iii = 0; iii < nums.size(); iii++) {
		ttt = nums[iii];
		int index = 0;
		while (index < 32) {
			bit_32[index] += (ttt & 1);
			ttt = ttt >> 1;
			index++;
		}
	}

	int ret = 0;
	for (int iii = 0; iii < 32; iii++) {
		bit_32[iii] %= 3;
		if (1 == bit_32[iii]) {
			const int ppp = 1 << iii;
			ret = ret | ppp;
		}
	}
	return ret;
    }
};

int main()
{
	Solution sln;
{
	vector<int> int_v = { 1, 1, 1, 2, 2, 2, 3, 4, 3, 3 };
	cout << sln.singleNumber(int_v) << endl;
}

{
	vector<int> int_v = { 4 };
	cout << sln.singleNumber(int_v) << endl;
}

	return 0;
}
