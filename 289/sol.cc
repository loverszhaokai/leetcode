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

// 0 -> 1 : -1
// 1 -> 0 : -2

void reset(vector<vector<int>> &board)
{
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == -1)
				board[i][j] = 1;
			else if (board[i][j] == -2)
				board[i][j] = 0;
}

inline bool origin_is_one(vector<vector<int>> &board, int i, int j)
{
	return board[i][j] == 1 || board[i][j] == -2;
}

void update_value(vector<vector<int>> &board, int i, int j, int c)
{
	if (board[i][j] == 1) {
		if (c < 2 || c > 3) {
			// 1 -> 0
			board[i][j] = -2;
		}
	} else if (board[i][j] == 0) {
		if (c == 3) {
			// 0 -> 1
			board[i][j] = -1;
		}
	}
}

void update_first_line(vector<vector<int>> &board)
{
	if (board.size() == 0)
		return;

	for (int i = 1; i < board[0].size() - 1; i++) {

		int c = 0;

		if (board[0][i - 1] == 1 || board[0][i - 1] == -2)
			c++;
		if (board[0][i + 1] == 1 || board[0][i + 1] == -2)
			c++;
		if (board.size() >= 2) {
			for (int j = i - 1; j <= i + 1; j++)
				if (board[1][j] == 1 || board[1][j] == -2)
					c++;
		}

		update_value(board, 0, i, c);
	}
}

void update_last_line(vector<vector<int>> &board)
{
	if (board.size() <= 1)
		return;

	const int last_line = board.size() - 1;

	for (int i = 1; i < board[last_line].size() - 1; i++) {
		int c = 0;
		if (board[last_line][i - 1] == 1 || board[last_line][i - 1] == -2)
			c++;
		if (board[last_line][i + 1] == 1 || board[last_line][i + 1] == -2)
			c++;
		for (int j = i - 1; j <= i + 1; j++)
			if (board[last_line - 1][j] == 1 || board[last_line - 1][j] == -2)
				c++;

		update_value(board, last_line, i, c);
	}
}

void update_first_column(vector<vector<int>> &board)
{
	if (board.size() == 0)
		return;

	if (board[0].size() == 0)
		return;

	for (int i = 1; i < board.size() - 1; i++) {

		int c = 0;

		if (board[i - 1][0] == 1 || board[i - 1][0] == -2)
			c++;
		if (board[i + 1][0] == 1 || board[i + 1][0] == -2)
			c++;

		if (board[0].size() >= 2) {
			for (int j = i - 1; j <= i + 1; j++)
				if (board[j][1] == 1 || board[j][1] == -2)
					c++;
		}

		update_value(board, i, 0, c);
	}
}

void update_last_column(vector<vector<int>> &board)
{
	if (board.size() == 0)
		return;

	if (board[0].size() < 2)
		return;

	const int last_column = board[0].size() - 1;

	for (int i = 1; i < board.size() - 1; i++) {

		int c = 0;

		if (board[i - 1][last_column] == 1 || board[i - 1][last_column] == -2)
			c++;
		if (board[i + 1][last_column] == 1 || board[i + 1][last_column] == -2)
			c++;

		for (int j = i - 1; j <= i + 1; j++)
			if (board[j][last_column - 1] == 1 || board[j][last_column - 1] == -2)
				c++;

		update_value(board, i, last_column, c);
	}
}

void update_lu_corner(vector<vector<int>> &board)
{
	int c = 0;

	if (board.size() > 1)
		if (origin_is_one(board, 1, 0))
			c++;

	if (board.size() > 0 && board[0].size() > 1) {

		if (origin_is_one(board, 0, 1))
			c++;

		if (board.size() > 1)
			if (origin_is_one(board, 1, 1))
				c++;
	}

	update_value(board, 0, 0, c);
}

void update_ru_corner(vector<vector<int>> &board)
{
	if (board[0].size() <= 1)
		return;

	int c = 0;

	const int right = board[0].size() - 1;

	if (board.size() > 1)
		if (origin_is_one(board, 1, right))
			c++;

	if (right >= 1) {
		if (origin_is_one(board, 0, right - 1))
			c++;
		if (board.size() > 1)
			if (origin_is_one(board, 1, right - 1))
				c++;
	}

	update_value(board, 0, right, c);
}

void update_ld_corner(vector<vector<int>> &board)
{
	if (board.size() <= 1)
		return;

	int c = 0;

	const int down = board.size() - 1;

	if (origin_is_one(board, down - 1, 0))
		c++;

	if (board[0].size() > 1) {
		if (origin_is_one(board, down, 1))
			c++;
		if (origin_is_one(board, down - 1, 1))
			c++;
	}

	update_value(board, down, 0, c);
}

void update_rd_corner(vector<vector<int>> &board)
{
	if (board.size() <= 1)
		return;

	if (board[0].size() <= 1)
		return;

	int c = 0;

	const int right = board[0].size() - 1;
	const int down = board.size() - 1;

	if (origin_is_one(board, down, right - 1))
		c++;

	if (origin_is_one(board, down - 1, right - 1))
		c++;
	if (origin_is_one(board, down - 1, right))
		c++;

	update_value(board, down, right, c);
}

int get_c(vector<vector<int>> &board, int x, int y)
{
	int c = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
			if (origin_is_one(board, i, j))
				c++;
	if (origin_is_one(board, x, y))
		c--;
	return c;
}

void update_main(vector<vector<int>> &board)
{
	for (int i = 1; i < board.size() - 1; i++)
		for (int j = 1; j < board[i].size() - 1; j++) {
			const int c = get_c(board, i, j);
			update_value(board, i, j, c);
		}
}

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {

		if (board.size() == 0 || board[0].size() == 0)
			return;

		update_first_line(board);
		update_last_line(board);

		update_first_column(board);
		update_last_column(board);

		update_lu_corner(board);
		update_ru_corner(board);

		update_ld_corner(board);
		update_rd_corner(board);

		update_main(board);

		reset(board);
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<vector<int>> board;
		vector<vector<int>> ret;
	} test_cases [] = {

		{
			{
				{ 1 }
			},
			{
				{ 0 }
			},
		},

		{
			{
				{ 1, 1 }
			},
			{
				{ 0, 0 }
			},
		},

		{
			{
				{ 1, 1 },
				{ 1, 1 },
			},
			{
				{ 1, 1 },
				{ 1, 1 },
			},
		},

		{
			{
				{ 1, 1, 1 },
				{ 1, 1, 1 },
				{ 1, 1, 1 },
			},
			{
				{ 1, 0, 1 },
				{ 0, 0, 0 },
				{ 1, 0, 1 },
			},
		},

		{
			{
				{ 1, 0, 1 },
				{ 0, 0, 0 },
				{ 1, 0, 1 },
			},
			{
				{ 0, 0, 0 },
				{ 0, 0, 0 },
				{ 0, 0, 0 },
			},
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		vector<vector<int>> board = tc.board;
		sln.gameOfLife(board);

		if ( tc.ret != board ) {
			cout << "Case #" << iii << " failed" << endl;
			return -1;
		}

	}

	return 0;
}
