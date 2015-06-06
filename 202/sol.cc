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

long long arr[64];

void init()
{
	for (int iii = 1; iii <= 64; iii++)
		arr[iii - 1] = pow(10.0, iii);
}

bool isPowTen(const long long n)
{
	for (int iii = 0; iii < 64; iii++)
		if (n == arr[iii])
			return true;
	return false;
}

class Solution {
public:
    bool isHappy(int n) {
	init();

        if (0 >= n)
		return false;
	if (1 == n)
		return true;

	vector<long long> nums;
	long long sum, rrr, mmm;

	mmm = n;
	nums.push_back(mmm);
	while (!isPowTen(mmm)) {
		sum = 0;
		while (0 != mmm) {
			rrr = mmm % 10;
			sum += rrr * rrr;
			mmm = mmm / 10;
		}
		mmm = sum;
		// cout << "mmm==" << mmm << endl;
		if (nums.end() == std::find(nums.begin(), nums.end(), mmm))
			nums.push_back(mmm);
		else
			return false;
	}
	return true;
    }
};

int main()
{
	Solution sln;

{
	cout << sln.isHappy(19) << endl;
}

{
	cout << sln.isHappy(12) << endl;
}

{
	cout << sln.isHappy(12222222) << endl;
}

{
	cout << sln.isHappy(3212341) << endl;
}

{
	cout << sln.isHappy(389238945) << endl;
}

	return 0;
}
