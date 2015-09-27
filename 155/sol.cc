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

struct MListNode {
	int val;
	struct MListNode *next;
	struct MListNode *next_min;

	MListNode(int v) : val(v), next(NULL), next_min(NULL) {};
};

class MinStack {
public:
	MinStack() {
		top_node = NULL;
		min_node = NULL;
	}

	void push(int x) {
		struct MListNode *node = new MListNode(x);
		node->next = top_node;
		top_node = node;

		if (min_node == NULL)
			min_node = node;
		else if (x < min_node->val) {
			node->next_min = min_node;
			min_node = node;
		}
	}

	void pop() {
		if (top_node == min_node)
			min_node = min_node->next_min;

		struct MListNode *orig_top = top_node;
		top_node = top_node->next;
		delete orig_top;
	}

	int top() {
		return top_node->val;
	}

	int getMin() {
		return min_node->val;
	}

private:
	struct MListNode *top_node;
	struct MListNode *min_node;
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
