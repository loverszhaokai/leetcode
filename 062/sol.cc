#include <cstdlib>

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

long long matrix[101][101];
bool flag = false;

void init()
{
	flag = true;
	
	matrix[0][1] = 1;
	for (int iii = 1; iii <= 100; iii++) {
		for (int jjj = 1; jjj <= 100; jjj++) {
			matrix[iii][jjj] = matrix[iii][jjj - 1] + matrix[iii - 1][jjj];
			// cout << "matrix[" << iii << "][" << jjj << "]=" << matrix[iii][jjj] << "  ";
		}
	}
}

class Solution {
public:
    int uniquePaths(int m, int n) {
	if (!flag)
		init();
	return matrix[m][n];
    }
};

int main()
{
	Solution sln;
	cout << sln.uniquePaths(3, 7) << endl;

	return 0;
}
