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
    int climbStairs(int n) {
        if (0 == n)
		return 0;
	if (1 == n)
		return 1;
	if (2 == n)
		return 2;

	vector<int> count_ways(n + 1, 0);
	count_ways[0] = 0;
	count_ways[1] = 1;
	count_ways[2] = 2;
	for (int iii = 3; iii < n + 1; iii++)
		count_ways[iii] = count_ways[iii - 1] + count_ways[iii - 2];
	return count_ways[n];
    }
};

int main()
{
	Solution sln;
	cout << sln.climbStairs(4) << endl;

	return 0;
}
