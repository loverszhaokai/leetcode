#include <cmath>

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
	for (int i = s.size(); i >= 1; i--) {
		ret += (s[i - 1] - 'A' + 1) * pow(26.0, s.size() - i);
	}
	return ret;
    }
};

int main()
{

	Solution sln;
	cout << sln.titleToNumber("ABC") << endl;

	return 0;
}
