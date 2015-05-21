#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

map<char, int> c_i;

class Solution {
public:
    int romanToInt(string s) {
	c_i['E'] = 0;
	c_i['I'] = 1;
	c_i['V'] = 5;
	c_i['X'] = 10;
	c_i['L'] = 50;
	c_i['C'] = 100;
	c_i['D'] = 500;
	c_i['M'] = 1000;

	s += "E";

	int ret = 0;
	int c, n;
	for (int iii = 0; iii < s.size() - 1; iii++) {
		c = c_i[s[iii] ];
		n = c_i[s[iii + 1] ];
		if (c >= n)
			ret += c;
		else
			ret -= c;
	}
	return ret;
    }
};

int main()
{
	Solution sln;
	cout << sln.romanToInt("") << endl;
	cout << sln.romanToInt("XI") << endl;
	cout << sln.romanToInt("DM") << endl;
	cout << sln.romanToInt("MD") << endl;
	cout << sln.romanToInt("CM") << endl;

	return 0;
}
