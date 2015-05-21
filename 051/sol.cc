#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int N;
vector<vector<string> > ret_v;
vector<string> matrix;

void GetAllArrangement(const vector<int> &agm_v, const vector<vector<bool> > &matrix_flag)
{
	if (N == agm_v.size()) {
		vector<string> next_matrix = matrix;
		for (int iii = 0; iii < agm_v.size(); iii++) {
			next_matrix[iii][ agm_v[iii] ] = 'Q';
		}
		ret_v.push_back(next_matrix);
		return;
	}

	for (int iii = 0; iii < N; iii++) {
		if (!matrix_flag[ agm_v.size() ][ iii ]) {
			vector<int> next_agm_v = agm_v;
			vector<vector<bool> > next_matrix_flag = matrix_flag;
			next_agm_v.push_back(iii);

			for (int jjj = agm_v.size() + 1; jjj < N; jjj++) {
				next_matrix_flag[jjj][iii] = true;
			}
			int kkk = 1;
			for (int jjj = agm_v.size() + 1; (jjj < N) && (iii + kkk < N); jjj++, kkk++) {
				next_matrix_flag[jjj][iii + kkk] = true;
			}
			kkk = 1;
			for (int jjj = agm_v.size() + 1; (jjj < N) && (iii - kkk >= 0); jjj++, kkk++) {
				next_matrix_flag[jjj][iii - kkk] = true;
			}

			GetAllArrangement(next_agm_v, next_matrix_flag);
		}
	}
}

class Solution {
public:

    vector<vector<string> > solveNQueens(int n) {
	N = n;	
	ret_v.clear();
	matrix.clear();

	if (0 == n)
		return ret_v;

	for (int iii = 0; iii < N; iii++)
		matrix.push_back(string(N, '.'));

	const vector<int> agm_v;
	const vector<vector<bool> > matrix_flag(N, vector<bool>(N, false));
	GetAllArrangement(agm_v, matrix_flag);

	return ret_v;
    }
};

int main()
{
	Solution sln;
	const vector<vector<string> > ret_v = sln.solveNQueens(3);
	cout << "ret_v.size()=" << ret_v.size() << endl;

{
	const vector<vector<string> > ret_v = sln.solveNQueens(0);

	cout << "ret_v.size()=" << ret_v.size() << endl;
}

{
	const vector<vector<string> > ret_v = sln.solveNQueens(1);
	cout << "ret_v.size()=" << ret_v.size() << endl;
}

{
	const vector<vector<string> > ret_v = sln.solveNQueens(2);
	cout << "ret_v.size()=" << ret_v.size() << endl;
}

{
	const vector<vector<string> > ret_v = sln.solveNQueens(4);
	cout << "ret_v.size()=" << ret_v.size() << endl;
}

{
	const vector<vector<string> > ret_v = sln.solveNQueens(5);
	cout << "ret_v.size()=" << ret_v.size() << endl;
}


	return 0;
}
