#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool is_all_9 = true;
		for (int iii = 0; iii < digits.size(); iii++) {
			if (digits[iii] != 9) {
				is_all_9 = false;
				break;
			}
		}

		if (is_all_9) {
			vector<int> ans(digits.size() + 1, 0);
			ans[0] = 1;
			return ans;
		}

		vector<int> ans = digits;
		for (int iii = ans.size() - 1; iii >= 0; iii--) {
			if (ans[iii] != 9) {
				ans[iii]++;
				break;
			} else {
				ans[iii] = 0;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;

{
	vector<int> digits = { 9, 9, 9, 9 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

{
	vector<int> digits = { 1, 1, 1, 1 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

{
	vector<int> digits = { 1 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

{
	vector<int> digits = { 1, 1, 0, 1, 1, 0, 1 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

{
	vector<int> digits = { 0 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

{
	vector<int> digits = { 9, 0, 8 };
	vector<int> ret = sln.plusOne(digits);
	print_vector(ret);
}

	return 0;
}
