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
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) {
			return { 1 };
		} else if (rowIndex == 1) {
			return { 1, 1 };
		}

		int guard, tmp;
		vector<int> ans(rowIndex + 1, 1);

		for (int iii = 2; iii <= rowIndex; iii++) {
			guard = 1;
			for (int jjj = 1; jjj < iii; jjj++) {
				tmp = ans[jjj];
				ans[jjj] += guard;
				guard = tmp;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sln;

{
	vector<int> ret = sln.getRow(1);
	print_vector(ret);
}

{
	vector<int> ret = sln.getRow(3);
	print_vector(ret);
}

{
	vector<int> ret = sln.getRow(4);
	print_vector(ret);
}

	return 0;
}
