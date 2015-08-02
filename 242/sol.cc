#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		char ccc;
		unordered_map<char, int> cm;

		for (int iii = 0; iii < s.size(); iii++) {
			cm[s[iii]]++;
		}

		for (int iii = 0; iii < t.size(); iii++) {
			ccc = t[iii];
			if (cm.find(ccc) == cm.end())
				return false;
			if (cm[ccc]-- == 0)
				return false;
		}

		return true;
	}
};

int main()
{
	Solution sln;

	cout << sln.isAnagram(string("anagram"), string("gramana")) << endl;
	cout << sln.isAnagram(string("anagram"), string("gramanm")) << endl;
	cout << sln.isAnagram(string("char"), string("caht")) << endl;
	cout << sln.isAnagram(string("char"), string("ccc")) << endl;

	return 0;
}
