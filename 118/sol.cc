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

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> matrix;

		for (int iii = 1; iii <= numRows; iii++)
			matrix.push_back(vector<int>(iii, 1));

		if (numRows < 3)
			return matrix;

		for (int iii = 3; iii <= numRows; iii++) {
			int jjj = 1;
			for (; jjj <= iii / 2; jjj++) {
				matrix[iii - 1][jjj] = matrix[iii - 2][jjj - 1] + matrix[iii - 2][jjj];
			}
			for (; jjj < iii - 1; jjj++) {
				matrix[iii - 1][jjj] = matrix[iii - 1][iii - 1 - jjj];
			}
		}

		return matrix;
	}
};

int main()
{
	Solution sln;

	vector<vector<int>> matrix = sln.generate(9);
	print_matrix(matrix);

	return 0;
}
