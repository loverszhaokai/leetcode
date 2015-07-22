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

void trim(string *_str)
{
	if (_str->size() == 0)
		return;
	int index = 0;
	while (index < _str->size() &&
		((*_str)[index] == ' ' || (*_str)[index] == '\t')) {
		index++;
	}
	*_str = _str->substr(index);

	index = _str->size() - 1;
	while (index &&
		((*_str)[index] == ' ' || (*_str)[index] == '\t')) {
		index--;
	}
	*_str = _str->substr(0, index + 1);
}

class Solution {
public:
	bool isNumber(string s) {
		int index = 0;
		bool has_int = false;
		trim(&s);

// .   -> point
// 0-9 -> integers
// e/E -> ee
// +/- -> sign

		if (index == s.size())
			return false;

		if (s[index] == '.') {
			goto after_point;
		} else if (s[index] >= '0' && s[index] <= '9') {
			has_int = true;
			goto integers;
		} else if (s[index] == '+' || s[index] == '-') {
			goto integers;
		}
		return false;

after_point:
// Can not have point again
		index++;
		if (index == s.size()) {
			if (has_int)
				return true;
			return false;
		}
		while (index < s.size()) {
			if (s[index] == 'e' || s[index] == 'E') {
				if (!has_int)
					return false;
				if (index + 1 == s.size())
					return false;
				goto signed_integer; // Does not contain point and e/E
			} else if (s[index] < '0' || s[index] > '9') {
				return false;
			}
			has_int = true;
			index++;
		}

		return true;

integers:
		index++;
		if (index == s.size()) {
			if (has_int)
				return true;
			return false;
		}
		while (index < s.size()) {
			if (s[index] == '.')
				goto after_point;
			if (s[index] == 'e' || s[index] == 'E') {
				if (!has_int)
					return false;
				if (index + 1 == s.size())
					return false;
				goto signed_integer;
			}
			if (s[index] < '0' || s[index] > '9') {
				return false;
			}
			has_int = true;
			index++;
		}
		return true;

// Does not contain point and e/E
signed_integer:

		index++;
		if (index == s.size()) {
			if (has_int)
				return true;
			return false;
		}

		if (s[index] == '+' || s[index] == '-') {
			if (index + 1 == s.size())
				return false;
			goto unsigned_integer; // Only contain integers
		} else if (s[index] < '0' || s[index] > '9') {
			return false;
		}
		has_int = true;
		goto unsigned_integer;

unsigned_integer:

		index++;
		if (index == s.size()) {
			if (has_int)
				return true;
			return false;
		}
		while (index < s.size()) {
			if (s[index] < '0' || s[index] > '9') {
				return false;
			}
			has_int = true;
			index++;
		}
		return true;
	}
};

int main()
{
	Solution sln;
	string s;

{
	s = "0";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = " 0.1 ";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "abc";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "1 a";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "2e10";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "2e-10";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "2e-10e2";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "e";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = ".1";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "3.";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}


{
	s = "-.";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "+.8";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "4e+";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "e9";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "11";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "0e";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "5e";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "0e1";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

{
	s = "4e+";
	cout << "s='" << s << "' is: " << sln.isNumber(s) << endl;
}

	return 0;
}
