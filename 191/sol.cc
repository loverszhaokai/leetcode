#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

typedef unsigned int uint32_t;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ret = 0;
		for (int i = 1; i <= 32; i++) {
			if (n & 1)
				ret++;
			n = n >> 1;
		}
		return ret;
	}
};

int main()
{

	Solution sln;
	cout << sln.hammingWeight(-1) << endl;

	return 0;
}
