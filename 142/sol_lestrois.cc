// Reference: https://leetcode.com/discuss/43324/a-c%23-6-line-solution

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
// The cycle has M nodes. At time t0, the slow is the first node in the cycle,
// the fast is the n node. t0 % M  == n
// After t seconds, slow and fast meet. t % M == (2t + n) % M
// t + k*M == 2t + n
// t = k * M - n
// k == 1 is the frist meet. At this time, t = M - n;
// So the first time slow and fast meet, slow has not scaned the cycle one time.
//
// t0 = x * M + n
//

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

	while (slow != fast) {
		if (NULL == slow->next)
			return NULL;
		if (NULL == fast->next || NULL == fast->next->next)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *node = head;
	ListNode *cycle_node = slow->next;

	// It takes t0 seconds from head to the first node of the cycle
	// t0 = x * M + n
	// It needs n seconds from meet to the first node of the cycle
	// So node and cycle_node will meet at the first node of the cycle
	while (node != cycle_node) {
		node = node->next;
		cycle_node = cycle_node->next;
	}

	return node;
    }
};

int main()
{
	ListNode n1(1), n2(2), n3(3), n4(4);

	n1.next = &n2;
	n2.next = &n1;
	n3.next = &n4;
	n4.next = &n4;

	Solution sln;
	cout << sln.detectCycle(&n1) << endl;
	cout << &n4 << endl;

	return 0;
}
