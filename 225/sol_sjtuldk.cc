#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::queue;
using std::string;
using std::vector;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		qe.push(x);
		for (int iii = 0; iii < qe.size() - 1; iii++) {
			qe.push(qe.front());
			qe.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		qe.pop();
	}

	// Get the top element.
	int top() {
		return qe.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return qe.empty();
	}

private:
	queue<int> qe;
};

int main()
{

{
	Stack stk;

	stk.push(1);
	stk.push(3);
	stk.push(5);
	stk.push(7);

	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
}

	return 0;
}
