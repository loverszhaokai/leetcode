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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (0 == matrix.size() || 0 == matrix.front().size())
		return false;

	int row_f_index = 0;
	int row_l_index = matrix.size() - 1;
	int mid;
	int row_index = row_f_index;

	while (row_l_index > row_f_index) {
		mid = (row_f_index + row_l_index) / 2;
		if (matrix[mid].front() <= target) {
			row_f_index = mid;
		} else {
			row_l_index = mid - 1;
		}
		if (row_l_index == 1 + row_f_index) {
			if (matrix[row_f_index].front() > target)
				return false;
			if (matrix[row_l_index].front() <= target)
				row_index = row_l_index;
			else
				row_index = row_f_index;
			break;
		}
		row_index = row_f_index;
	}

	int column_f_index = 0;
	int column_l_index = matrix[0].size() - 1;
	while (column_l_index > column_f_index) {
		mid = (column_f_index + column_l_index) / 2;
		if (matrix[row_index][mid] < target) {
			column_f_index = mid + 1;
		} else if (matrix[row_index][mid] == target) {
			return true;
		} else {
			column_l_index = mid;
		}
	}

	if (matrix[row_index][column_f_index] == target)
		return true;
	return false;
    }
};

int main()
{
	Solution sln;

{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 3) << endl;
}

{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 34) << endl;
}

{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 10) << endl;
}

{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 23) << endl;
}


{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 20) << endl;
}


{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 50) << endl;
}


{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 100) << endl;
}

{
	vector<vector<int>> matrix = {
		{ 1, 3, 5, 7, },
		{ 10, 11, 16, 20, },
		{ 23, 30, 34, 50, },
	};
	cout << sln.searchMatrix(matrix, 19) << endl;
}

{
	vector<vector<int>> matrix = {
		{ -8,-6,-6,-4,-2,-1,-1,-1,0,1,2,4,6,7,7 },
		{ 10,10,12,13,13,14,14,16,17,17,17,17,17,18,19 },
		{ 22,24,26,28,29,31,32,34,34,34,34,36,38,39,39 },
		{ 40,40,41,43,43,44,46,47,49,49,50,52,53,55,55 },
		{ 56,57,59,61,62,64,65,65,66,67,68,68,69,70,71 },
		{ 74,75,77,77,79,79,79,80,81,83,85,87,88,89,89 },
		{ 91,93,94,96,97,98,99,99,100,100,102,104,105,107,107 },
		{ 110,112,114,114,115,117,117,118,118,120,120,121,123,124,124 },
		{ 127,127,129,131,133,134,134,135,137,139,139,140,142,143,144 },
		{ 145,146,147,149,151,151,153,155,156,156,158,160,162,162,163 },
	};
	cout << sln.searchMatrix(matrix, 107) << endl;
}


	return 0;
}
