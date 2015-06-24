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
        vector<int> row_flag(matrix.size(), 0);
        vector<int> column_flag(matrix.front().size(), 0);

	for (int iii = 0; iii < matrix.size(); iii++) {
		for (int jjj = 0; jjj < matrix[iii].size(); jjj++) {
			if (0 == matrix[iii][jjj]) {
				row_flag[iii] = 1;
				column_flag[jjj] = 1;
			}
		}
	}

	for (int iii = 0; iii < row_flag.size(); iii++) {
		if (1 == row_flag[iii]) {
			for (int jjj = 0; jjj < matrix[iii].size(); jjj++)
				matrix[iii][jjj] = 0;
		}
	}

	for (int iii = 0; iii < column_flag.size(); iii++) {
		if (1 == column_flag[iii]) {
			for (int jjj = 0; jjj < matrix.size(); jjj++)
				matrix[jjj][iii] = 0;
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
