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

vector<vector<int>> matrix;

void recursiveRun(int start, const int pos, const int nnn)
{
	if (start > nnn * nnn)
		return;
	// First line
	for (int iii = pos; iii <= nnn - pos - 1; iii++) {
		matrix[pos][iii] = start++;
	}
	// Last column
	for (int iii = pos + 1; iii <= nnn - pos - 1; iii++) {
		matrix[iii][nnn - pos - 1] = start++;
	}
	// Last line
	for (int iii = nnn - pos - 2; iii >= pos; iii--) {
		matrix[nnn - pos - 1][iii] = start++;
	}
	// First column
	for (int iii = nnn - pos - 2; iii >= pos + 1; iii--) {
		matrix[iii][pos] = start++;
	}
	recursiveRun(start, pos + 1, nnn);
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        matrix = vector<vector<int>>(n, vector<int>(n ,0));
	recursiveRun(1, 0, n);
	return matrix;
    }
};

int main()
{
	Solution sln;

{
	const vector<vector<int>> ret = sln.generateMatrix(1);
	print_matrix(ret);
}

{
	const vector<vector<int>> ret = sln.generateMatrix(2);
	print_matrix(ret);
}

{
	const vector<vector<int>> ret = sln.generateMatrix(3);
	print_matrix(ret);
}

{
	const vector<vector<int>> ret = sln.generateMatrix(4);
	print_matrix(ret);
}



	return 0;
}
