/*
 * leetcode - solutions of leetcode
 * --------------------------------
 *
 * Copyright 2015 Kai Zhao <loverszhao@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 */

#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

#define MAX_SIZE 101

int is_visit[MAX_SIZE][MAX_SIZE];

int solve(const vector<vector<int> > &grid, const int x, const int y)
{
	if (x >= grid.size() || y >= grid[0].size())
		return 0;

	if (grid[x][y] == 1)
		return 0;

	if (x == grid.size() - 1 && y == grid[0].size() - 1)
		return 1;

	int ret = 0;

	if (is_visit[x][y+1] != -1)
		ret += is_visit[x][y+1];
	else
		ret += solve(grid, x, y + 1);

	if (is_visit[x+1][y] != -1)
		ret += is_visit[x+1][y];
	else
		ret += solve(grid, x + 1, y);

	is_visit[x][y] = ret;

	return ret;
}

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
			return 0;

		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				is_visit[i][j] = -1;

		return solve(obstacleGrid, 0, 0);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<int> > grid;
		int ret;
	} test_cases [] = {

		{
			{
				{ 0, 0, 0 },
				{ 0, 1, 0 },
				{ 0, 0, 0 },
			},
			2
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.uniquePathsWithObstacles(tc.grid) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
