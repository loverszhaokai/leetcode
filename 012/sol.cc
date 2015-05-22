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
    string intToRoman(int num) {
	string ret_s = "";
	if (num >= 1000) {
		ret_s += string(num / 1000, 'M');
		num = num % 1000;
	}
	if (num >= 900) {
		ret_s += "CM";
		num = num - 900;
	}
	if (num >= 500) {
		ret_s += "D";
		num = num - 500;
	}
	if (num >= 400) {
		ret_s += "CD";
		num = num - 400;
	}
	if (num >= 100) {
		ret_s += string(num / 100, 'C');
		num = num % 100;
	}
	if (num >= 90) {
		ret_s += "XC";
		num = num - 90;
	}
	if (num >= 50) {
		ret_s += "L";
		num = num - 50;
	}
	if (num >= 40) {
		ret_s += "XL";
		num = num - 40;
	}
	if (num >= 10) {
		ret_s += string(num / 10, 'X');
		num = num % 10;
	}
	if (num >= 9) {
		ret_s += "IX";
		num = num - 9;
	}
	if (num >= 5) {
		ret_s += "V";
		num = num - 5;
	}
	if (num >= 4) {
		ret_s += "IV";
		num = num - 4;
	}
	if (num >= 1) {
		ret_s += string(num, 'I');
	}
	return ret_s;
    }
};

int main()
{
	Solution sln;
	cout << sln.intToRoman(0) << endl;
	cout << sln.intToRoman(1599) << endl;
	cout << sln.intToRoman(3500) << endl;

	return 0;
}
