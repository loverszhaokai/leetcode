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
    int minPathSum(vector<vector<int>>& grid) {
	const int mmm = grid.size();
	const int nnn = grid.front().size();

	// First line
	for (int iii = 1; iii < nnn; iii++)
		grid[0][iii] += grid[0][iii - 1];

	// First column
	for (int iii = 1; iii < mmm; iii++)
		grid[iii][0] += grid[iii - 1][0];

	for (int iii = 1; iii < mmm; iii++) {
		for (int jjj = 1; jjj < nnn; jjj++) {
			grid[iii][jjj] += std::min(grid[iii - 1][jjj], grid[iii][jjj - 1]);
		}
	}

	return grid.back().back();
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
	vector<vector<int> > matrix = {
		{ 1, 2, 3, },
		{ 6, 7, 8, },
		{ 11, 12, 13 },
	};

	cout << sln.minPathSum(matrix) << endl;
}

{
}


	return 0;
}
