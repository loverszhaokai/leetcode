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
    void rotate(vector<vector<int>>& matrix) {
        const int NNN = matrix.size();
	int temp;
	for (int iii = 0; iii < NNN / 2; iii++) {
		for (int jjj = 0; jjj < NNN - 1 - 2 * iii; jjj++) {
			temp = matrix[iii][iii + jjj];
			matrix[iii][iii + jjj] = matrix[NNN - 1 - (iii + jjj)][iii];
			matrix[NNN - 1 - (iii + jjj)][iii] = matrix[NNN - 1 - iii][NNN - 1 - (iii + jjj)];
			matrix[NNN - 1 - iii][NNN - 1 - (iii + jjj)] = matrix[iii + jjj][NNN - 1 - iii];
			matrix[iii + jjj][NNN - 1 - iii] = temp;
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
	vector<vector<int> > matrix = {
		{ 1, 2, 3, 4, 5  },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14,15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 },
	};

	print_matrix(matrix);

	sln.rotate(matrix);

	print_matrix(matrix);
}

{
}


	return 0;
}
