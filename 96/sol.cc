#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int numTrees(int n) {

	if (0 == n)
		return 0;

	int *arr = new int[n+1];

	arr[0] = 1;
	arr[1] = 1;
	for (int iii = 2; iii <= n; iii++) {
		int sum = 0;
		for (int jjj = 0; jjj < iii; jjj++)
			sum += arr[jjj] * arr[iii - 1 - jjj];
		arr[iii] = sum;
	}

	return arr[n];
    }
};

int main()
{
	Solution sln;
	cout << sln.numTrees(0) << endl;
	cout << sln.numTrees(1) << endl;
	cout << sln.numTrees(2) << endl;
	cout << sln.numTrees(3) << endl;
	cout << sln.numTrees(4) << endl;
	cout << sln.numTrees(5) << endl;
	cout << sln.numTrees(18) << endl;
	return 0;
}
