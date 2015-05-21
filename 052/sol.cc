#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int N;
int ans;

void GetAllArrangement(const vector<int> &agm_v, const vector<vector<bool> > &matrix_flag)
{
	if (N == agm_v.size()) {
		ans++;
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

    int totalNQueens(int n) {
	N = n;	
	ans = 0;

	if (0 == n)
		return 0;

	const vector<int> agm_v;
	const vector<vector<bool> > matrix_flag(N, vector<bool>(N, false));
	GetAllArrangement(agm_v, matrix_flag);

	return ans;
    }
};

int main()
{
	Solution sln;

{
	const int ret = sln.totalNQueens(0);
	cout << "ret_v.size()=" << ret << endl;
}

{
	const int ret = sln.totalNQueens(1);
	cout << "ret_v.size()=" << ret << endl;
}
{
	const int ret = sln.totalNQueens(2);
	cout << "ret_v.size()=" << ret << endl;
}
{
	const int ret = sln.totalNQueens(3);
	cout << "ret_v.size()=" << ret << endl;
}
{
	const int ret = sln.totalNQueens(4);
	cout << "ret_v.size()=" << ret << endl;
}
{
	const int ret = sln.totalNQueens(5);
	cout << "ret_v.size()=" << ret << endl;
}

	return 0;
}
