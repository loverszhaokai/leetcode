#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
	int ret = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1]) {
			ret += prices[i] - prices[i - 1];
		}
	}
	return ret;
    }
};

int main()
{

	vector<int> int_v = { 1, 2, 3, 4, 5 };
	vector<int> int_v2 = { 1, 2, 3, 4, 5, 0 };

	Solution sln;
	cout << sln.maxProfit(int_v) << endl;
	cout << sln.maxProfit(int_v2) << endl;


	return 0;
}
