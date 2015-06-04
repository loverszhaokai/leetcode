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

vector<vector<vector<int> > > matrix;

void init(const int size)
{
	matrix.clear();
	matrix.push_back(vector<vector<int> >(1, vector<int>(1, 0)));

	for (int iii = 2; iii <= size; iii++) {
		vector<vector<int> > new_permutes;
		vector<int> pos_v(iii, 0);
		for (int lll = 0; lll < iii; lll++)
			pos_v[lll] = lll;
		new_permutes.push_back(pos_v);

		for (int jjj = iii - 2; jjj >= 0; jjj--) {
			const vector<vector<int> > permutes = matrix[iii - jjj - 2];
			for (int kkk = jjj + 1; kkk < iii; kkk++) {
				vector<int> pos_v(iii, 0);
				for (int lll = 0; lll < pos_v.size(); lll++)
					pos_v[lll] = lll;
				const int temp = pos_v[jjj];
				pos_v[jjj] = pos_v[kkk];
				pos_v[kkk] = temp;
				std::sort(pos_v.begin() + jjj + 1, pos_v.end());
				for (int lll = 0; lll < permutes.size(); lll++) {
					vector<int> new_pos_v = pos_v;
					for (int mmm = jjj + 1; mmm < iii; mmm++) {
						new_pos_v[mmm] = pos_v[jjj + 1 + permutes[lll][mmm - jjj - 1] ];
					}
					new_permutes.push_back(new_pos_v);
				}
			}
		}
		matrix.push_back(new_permutes);
	}
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int> > ret;
	if (0 == nums.size())
		return ret;

	init(nums.size());
	const vector<vector<int> > pos_v = matrix.back();

	for (int iii = 0; iii < pos_v.size(); iii++) {
		vector<int> temp(nums.size(), 0);
		for (int jjj = 0; jjj < nums.size(); jjj++) {
			temp[jjj] = nums[ pos_v[iii][jjj] ];
		}
		ret.push_back(temp);
	}
	return ret;
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
	vector<int> nums = { 5, 4, 6, 2 };

	const vector<vector<int> > matrix = sln.permute(nums);
	print_matrix(matrix);
}

	return 0;
}
