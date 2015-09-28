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


vector<vector<int> > is_visit;

const int dx[4] = { -1, 0, 1,  0 };
const int dy[4] = {  0, 1, 0, -1 };

bool solve(const vector<vector<char> > &board, const string &word,
	const int index, const int x, const int y)
{
	int nx, ny;

	is_visit[x][y] = 1;

	if (index >= word.size())
		return true;

	for (int i = 0; i < 4; i++) {

		nx = x + dx[i];
		ny = y + dy[i];

		if (nx < 0 || nx >= board.size())
			continue;

		if (ny < 0 || ny >= board[0].size())
			continue;

		if (!is_visit[nx][ny] && word[index] == board[nx][ny]) {

			if (solve(board, word, index + 1, nx, ny))
				return true;
		}
	}

	is_visit[x][y] = 0;
	return false;
}


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {

		if (word.size() == 0)
			return true;

		if (board.size() == 0 || board[0].size() == 0)
			return false;

		is_visit = vector<vector<int> > (board.size(),
			vector<int> (board[0].size(), 0));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {

				if (board[i][j] == word[0]) {

					if (solve(board, word, 1, i, j))
						return true;
				}
			}
		}

		return false;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<char> > board;
		string word;
		bool ret;
	} test_cases [] = {

		{
			{
				{ 'A', 'B', 'C', 'E' },
				{ 'S', 'F', 'C', 'S' },
				{ 'A', 'D', 'E', 'E' },
			},
			"ABCCED",
			true,
		},

		{
			{
				{ 'A', 'B', 'C', 'E' },
				{ 'S', 'F', 'C', 'S' },
				{ 'A', 'D', 'E', 'E' },
			},
			"ABCESEEDAS",
			true,
		},

		{
			{
				{ 'A', 'B', 'C', 'E' },
				{ 'S', 'F', 'C', 'S' },
				{ 'A', 'D', 'E', 'E' },
			},
			"ABCB",
			false,
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		if ( tc.ret != sln.exist(tc.board, tc.word) ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
