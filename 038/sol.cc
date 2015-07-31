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

string int_to_string(int n)
{
	int r;
	string str = "";

	while (true) {
		r = n % 10;
		n = n / 10;
		str = string(1, r + '0') + str;
		if (!n)
			break;
	}
	return str;
}


class Solution {
public:
	string countAndSay(int n) {
		string str = "1";
		int iii = 1;

		while (iii++ < n) {
			string tmp = "";
			char guard = str[0];
			int count = 1;

			for (int jjj = 1; jjj < str.size(); jjj++) {
				if (str[jjj] == guard) {
					count++;
				} else {
					tmp += int_to_string(count) + string(1, guard);
					guard = str[jjj];
					count = 1;
				}
			}
			tmp += int_to_string(count) + string(1, guard);
			str = tmp;
		}
		return str;
	}
};

int main()
{
	Solution sln;

cout << sln.countAndSay(3) << endl;
cout << sln.countAndSay(13) << endl;

	return 0;
}
