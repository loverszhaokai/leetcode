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
    vector<string> generateParenthesis(int n) {
	vector<string> ret;
        vector<vector<string> > matrix;

	if (0 == n)
		return ret;

	matrix.push_back(vector<string>(1, "()"));

	for (int iii = 2; iii <= n; iii++) {
		vector<string> strs;
		string sss = string(iii, '(');
		sss += string(iii, ')');
		strs.push_back(sss);
		for (int jjj = iii - 1; jjj >= 1; jjj--) {
			sss = string(jjj, '(');
			sss += ")";
			for (int kkk = 0; kkk < matrix[iii - 2].size(); kkk++) {
				if (sss.substr(0, jjj - 1) == matrix[iii - 2][kkk].substr(0, jjj - 1))
					strs.push_back(sss + matrix[iii - 2][kkk].substr(jjj - 1));
			}
		}
		matrix.push_back(strs);
	}

	return matrix.back();
    }
};

int main()
{
	Solution sln;

{
	vector<string> ret = sln.generateParenthesis(3);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << "  ";
	}
	cout << endl;
}

{
	vector<string> ret = sln.generateParenthesis(4);
	for (int iii = 0; iii < ret.size(); iii++) {
		cout << ret[iii] << "  ";
	}
	cout << endl;
}


	return 0;
}
