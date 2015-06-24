#include <climits>
#include <cmath>

#include <algorithm>
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
    void setZeroes(vector<vector<int>>& matrix) {
	if (0 == matrix.size() || 0 == matrix.front().size())
		return;

	bool is_first_row_zero = false;
	bool is_first_column_zero = false;
	
	for (int iii = 0; iii < matrix.size(); iii++) {
		if (0 == matrix[iii][0]) {
			is_first_column_zero = true;
			break;
		}
	}

	for (int iii = 0; iii < matrix.front().size(); iii++) {
		if (0 == matrix[0][iii]) {
			is_first_row_zero = true;
			break;
		}
	}

	for (int iii = 1; iii < matrix.size(); iii++) {
		for (int jjj = 1; jjj < matrix.front().size(); jjj++) {
			if (0 == matrix[iii][jjj]) {
				matrix[iii][0] = 0;
				matrix[0][jjj] = 0;
			}
		}
	}

	for (int iii = 1; iii < matrix.size(); iii++) {
		if (0 == matrix[iii][0]) {
			for (int jjj = 1; jjj < matrix.front().size(); jjj++) {
				matrix[iii][jjj] = 0;
			}
		}
	}

	for (int iii = 1; iii < matrix.front().size(); iii++) {
		if (0 == matrix[0][iii]) {
			for (int jjj = 1; jjj < matrix.size(); jjj++) {
				matrix[jjj][iii] = 0;
			}
		}
	}

	if (is_first_row_zero) {
		for (int iii = 0; iii < matrix.front().size(); iii++) {
			matrix[0][iii] = 0;
		}
	}

	if (is_first_column_zero) {
		for (int iii = 0; iii < matrix.size(); iii++) {
			matrix[iii][0] = 0;
		}
	}
    }
};

void print_matrix(const vector<vector<int> > &matrix)
{
	for (int iii = 0; iii < matrix.size(); iii++) {
		for (int jjj = 0; jjj < matrix[iii].size(); jjj++) {
			cout << matrix[iii][jjj] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	Solution sln;

{
	vector<vector<int>> matrix = {
		{ 1, 1, 1, 0},
		{ 0, 1, 1, 2},
		{ 1, 0, 1, 1}
	};

	sln.setZeroes(matrix);

	print_matrix(matrix);
}

{
	vector<vector<int>> matrix = {
		{ 1, 1, 1, 0},
		{ 1, 1, 1, 2},
		{ 1, 0, 1, 1}
	};

	sln.setZeroes(matrix);

	print_matrix(matrix);
}

	return 0;
}
