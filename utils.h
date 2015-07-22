#ifndef _UTILS_H_
#define _UTILS_H_

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<class T>
void print_vector(const vector<T> &_nums, const int _n = 10)
{
	cout << "[vector] nums=" << endl;
	cout << "\t";
	for (int iii = 0; iii < _nums.size(); iii++) {
		cout << _nums[iii] << ", ";
		if (0 == (iii + 1) % _n)
			cout << endl << "\t";
	}

	cout << endl;
}

template<class T>
void print_matrix(const vector<vector<T> > &_matrix)
{
	cout << "[vector<vector>] matrix=" << endl;

	for (int iii = 0; iii < _matrix.size(); iii++) {
		cout << "\t";
		for (int jjj = 0; jjj < _matrix[iii].size(); jjj++) {
			cout << _matrix[iii][jjj] << ", ";
		}
		cout << endl;
	}
	cout << endl;
}


#endif
