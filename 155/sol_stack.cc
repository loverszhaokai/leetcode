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

class MinStack {
public:
	MinStack() {
	}

	void push(int x) {

		if (stk.empty()) {
			stk.push(0);
			min_val = x;
		} else {
			stk.push((long long)x - min_val);
			if (x < min_val)
				min_val = x;
		}
	}

	void pop() {
		long long top = stk.top();
		if (top < 0)
			min_val = min_val - top;
		stk.pop();
	}

	int top() {
		long long top = stk.top();
		if (top < 0)
			return (int)min_val;
		return (int)(top + min_val);
	}

	int getMin() {
		return (int)min_val;
	}

private:
	stack<long long> stk;
	long long min_val;
};

int main()
{
	MinStack ms;

	ms.push(10);
	ms.push(11);
	ms.push(9);
	ms.push(19);
	ms.push(4);

	cout << ms.getMin() << endl;
	cout << ms.top() << endl;
	cout << endl;

	ms.pop();

	cout << ms.getMin() << endl;
	cout << ms.top() << endl;
	cout << endl;


	ms.pop();

	cout << ms.getMin() << endl;
	cout << ms.top() << endl;
	cout << endl;

	ms.pop();

	cout << ms.getMin() << endl;
	cout << ms.top() << endl;
	cout << endl;

	ms.pop();

	cout << ms.getMin() << endl;
	cout << ms.top() << endl;
	cout << endl;

	return 0;
}
