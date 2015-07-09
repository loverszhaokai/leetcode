#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::vector;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> temp_stk;
	
	while (!stk.empty()) {
		temp_stk.push(stk.top());
		stk.pop();
	}

	temp_stk.pop();
	while (!temp_stk.empty()) {
		stk.push(temp_stk.top());
		temp_stk.pop();
	}
    }

    // Get the front element.
    int peek(void) {
        stack<int> temp_stk;
	
	while (!stk.empty()) {
		temp_stk.push(stk.top());
		stk.pop();
	}

	const int ret = temp_stk.top();
	while (!temp_stk.empty()) {
		stk.push(temp_stk.top());
		temp_stk.pop();
	}
	return ret;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }

private:
	stack<int> stk;
};

int main()
{
	Queue qe;

{
	qe.push(1);
	qe.push(2);
	qe.push(3);

	cout << "top=" << qe.peek() << endl;

	qe.pop();

	qe.push(4);

	while (!qe.empty()) {
		cout << qe.peek() << endl;
		qe.pop();
	}
}

	return 0;
}
