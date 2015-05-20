#include <cmath>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
	string convertToTitle(int n) {
        	string ret = "";
		int x = 0;
		while (0 != n) {
			x = n % 26;
			n = n / 26;
			if (0 == x) {
				n--;
				x = 26;
			}
			ret = string(1, 'A' + x - 1) + ret;
		}
		return ret;
	}
};

int main()
{

	Solution sln;
	cout << sln.convertToTitle(53) << endl;
	cout << sln.convertToTitle(1) << endl;
	cout << sln.convertToTitle(731) << endl;

	return 0;
}
