#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {

public:
    int singleNumber(vector<int>& nums) {
	int ret = nums[0];

	for (int i = 1; i < nums.size(); i++) 
		ret ^= nums[i];

	return ret;        
    }
};

int main()
{
	Solution sln;
	vector<int> int_v = { 1, 1, 2, 3, 4, 4, 3 };
	cout << sln.singleNumber(int_v) << endl;
	return 0;
}

