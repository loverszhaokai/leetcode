#include <cmath>

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
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
	if (0 == prices.size())
		return 0;
	int min_price = prices[0];
	int max_price = prices[0];
	for (int iii = 1; iii < prices.size(); iii++) {
		if (prices[iii] < min_price) {
			min_price = prices[iii];
			max_price = min_price;
		} else if (prices[iii] > max_price) {
			max_price = prices[iii];
			maxProfit = std::max(maxProfit, max_price - min_price);
		}
	}
	return maxProfit;
    }
};

int main()
{
	Solution sln;

{
	vector<int> nums = { 1, 1, 2, 2, 2, 2, 0, 2, 0, 1, 0, 2 };
	cout << sln.maxProfit(nums) << endl;
}

{
	vector<int> nums = { 2, 1 };
	cout << sln.maxProfit(nums) << endl;
}

{
	vector<int> nums = { 1, 2, 10 };
	cout << sln.maxProfit(nums) << endl;
}

{
	vector<int> nums = { 8, 9, 10, 1, 7 };
	cout << sln.maxProfit(nums) << endl;
}

	return 0;
}
