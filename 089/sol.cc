#include <cmath>

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
    vector<int> grayCode(int n) {
        vector<int> ret;
	ret.push_back(0);

	if (n == 0)
		return ret;

	ret.push_back(1);

	if (n == 1)
		return ret;

	for (int iii = 1; iii < n; iii++) {
		const int add = pow(2.0, iii);
		for (int jjj = ret.size() - 1; jjj >= 0; jjj--)
			ret.push_back(add + ret[jjj]);
	}

	return ret;
    }
};

int main()
{
	Solution sln;

{
	vector<int> ret = sln.grayCode(2);
	cout << "n=" << 2 << endl;
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << "  ";
	}
	cout << endl;
}

{
	vector<int> ret = sln.grayCode(4);
	cout << "n=" << 4 << endl;
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << "  ";
	}
	cout << endl;
}

	return 0;
}
