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

		int low = 0, high = 0;
		for (int iii = 0; iii < nums.size(); iii++) {
			low = (low ^ nums[iii]) & ~high;
			high = (high ^ nums[iii]) & ~low;
		}
		return low;
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
