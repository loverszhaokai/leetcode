// Reference: https://leetcode.com/discuss/43785/my-o-1-space-and-o-n-time-python-ac-code

#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// slow: 1 nodes/sec
// fast: 2 nodes/sec
//
// The cycle has M nodes. When the slow is the first node, fast is the n node.
// After t seconds, slow and fast meet. t % M == (2t + n) % M
// t + k*M == 2t + n
// t = k * M - n
// k == 1 is the frist meet. At this time, t = M - n;
// So the first time slow and fast meet, slow has not scaned the cycle one time.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
	if (NULL == head || NULL == head->next)
		return NULL;

	// Reverse head
	ListNode *slow = head;
	ListNode *fast = head->next;

	int slow_count = 0;

	while (slow != fast) {
		if (NULL == slow->next)
			return NULL;
		if (NULL == fast->next || NULL == fast->next->next)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
		slow_count++;
	}

	ListNode *meet = slow;
	
	ListNode *node = meet->next;
	int cycle_count = 0;

	while (node != meet) {
		node = node->next;
		cycle_count++;
	}

	node = head;
	const int n = slow_count - cycle_count;
	for (int iii = 0; iii < n; iii++)
		node = node->next;

	slow = meet->next;
	while (node != slow) {
		node = node->next;
		slow = slow->next;
	}
	return node;
    }
};

int main()
{
	ListNode n1(1), n2(2), n3(3), n4(4);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n4;

	Solution sln;
	cout << sln.detectCycle(&n1) << endl;
	cout << &n4 << endl;

	return 0;
}
