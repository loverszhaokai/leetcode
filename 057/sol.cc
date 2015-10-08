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

struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// including @from and @to
void delete_index(vector<Interval> &intervals, int from, int to)
{
	intervals.erase(intervals.begin() + from, intervals.begin() + to + 1);
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

		if (intervals.size() == 0) {
			intervals.push_back(newInterval);
			return intervals;
		}

		int left = -1;
		int right = -1;

		for (int i = 0; i < intervals.size(); i++) {

			if (intervals[i].start >= newInterval.start && left == -1)
				left = i;

			if (intervals[i].start >= newInterval.end && right == -1) {
				right = i;
				break;
			}
		}

		Interval &last_interval = intervals.back();

		if (last_interval.end < newInterval.start) {
			intervals.push_back(newInterval);
			return intervals;
		} else if (last_interval.start <= newInterval.start) {
			if (last_interval.end < newInterval.end)
				last_interval.end = newInterval.end;
			return intervals;
		} else {
			// left != -1
			Interval *before_left = NULL;

			if (left != 0)
				before_left = &intervals[left - 1];

			if (left == 0 || before_left->end < newInterval.start) {
				if (left == right) {
					if (intervals[left].start != newInterval.end)
						intervals.insert(intervals.begin() + left, newInterval);
					else
						intervals[left].start = newInterval.start;
					return intervals;
				} else if (right == -1) {

					intervals[left].start = newInterval.start;
					if (last_interval.end >= newInterval.end)
						intervals[left].end = last_interval.end;
					else
						intervals[left].end = newInterval.end;

					if (left + 1 <= intervals.size() - 1)
						delete_index(intervals, left + 1, intervals.size() - 1);
					return intervals;

				} else {

					intervals[left].start = newInterval.start;

					if (intervals[right].start == newInterval.end) {

						intervals[left].end = intervals[right].end;

						if (left + 1 <= right)
							delete_index(intervals, left + 1, right);
						return intervals;

					} else {
						Interval &before_right = intervals[right - 1];

						if (before_right.end < newInterval.end)
							intervals[left].end = newInterval.end;
						else
							intervals[left].end = before_right.end;

						if (left + 1 <= right - 1)
							delete_index(intervals, left + 1, right - 1);
						return intervals;
					}
				}
			} else {

				if (right == -1) {
					if (last_interval.end >= newInterval.end)
						before_left->end = last_interval.end;
					else
						before_left->end = newInterval.end;

					if (left <= intervals.size() - 1)
						delete_index(intervals, left, intervals.size() - 1);
					return intervals;
				} else {

					if (intervals[right].start == newInterval.end) {

						before_left->end = intervals[right].end;

						if (left <= right)
							delete_index(intervals, left, right);
						return intervals;

					} else {
						Interval &before_right = intervals[right - 1];

						if (before_right.end < newInterval.end)
							before_left->end = newInterval.end;
						else
							before_left->end = before_right.end;

						if (left <= right - 1)
							delete_index(intervals, left, right - 1);
						return intervals;
					}
				}
			}
		}

		return intervals;
	}
};

int main()
{
	Solution sln;

	struct TestCase {
		vector<Interval> intervals;
		Interval newInterval;
		vector<Interval> ret;
	} test_cases [] = {

		{
			{ Interval(1, 3), Interval(6, 9) },
			Interval(2, 5),
			{ Interval(1, 5), Interval(6, 9) },
		},

		{
			{ Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(4, 9),
			{ Interval(1, 2), Interval(3, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(1, 2),
			{ Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(17, 20),
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16), Interval(17, 20) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(1, 20),
			{ Interval(1, 20) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(1, 9),
			{ Interval(1, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(3, 9),
			{ Interval(3, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(3, 5),
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(3, 10),
			{ Interval(3, 10), Interval(12, 16) },
		},

		{
			{ Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) },
			Interval(4, 6),
			{ Interval(3, 7), Interval(8, 10), Interval(12, 16) },
		},

		{
			{ },
			Interval(4, 6),
			{ Interval(4, 6) },
		},

	};

	for (int iii = 0; iii < sizeof(test_cases) / sizeof(TestCase); iii++) {

		TestCase &tc = test_cases[iii];

		vector<Interval> ret = sln.insert(tc.intervals, tc.newInterval);

		if (tc.ret.size() != ret.size()) {
			cout << "Case #" << iii << " failed" << endl;
			cout << "expected size=" << tc.ret.size() << endl;
			cout << "actual   size=" << ret.size() << endl;
			return -1;
		}

		for (int i = 0; i < ret.size(); i++) {
			if (tc.ret[i].start != ret[i].start && tc.ret[i].end != ret[i].end) {
				cout << "Case #" << iii << " failed" << endl;
				cout << "expected=" << tc.ret[i].start << "," << tc.ret[i].end << endl;
				cout << "actual  =" << ret[i].start << "," << ret[i].end << endl;
				return -1;
			}
		}
	}

	return 0;
}
