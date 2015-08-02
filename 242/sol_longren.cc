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

		int counts[256] = { 0 };

		for (int iii = 0; iii < s.size(); iii++) {
			counts[s[iii]]++;
			counts[t[iii]]--;
		}

		for (int iii = 'a'; iii <= 'z'; iii++) {
			if (counts[iii])
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
