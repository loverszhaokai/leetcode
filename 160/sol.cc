#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *nodeA, *nodeB;
		int lenA, lenB;

		if (!headA || !headB)
			return NULL;

		nodeA = headA;
		nodeB = headB;
		lenA = 0;
		lenB = 0;

		while (nodeA) {
			lenA++;
			nodeA = nodeA->next;
		}
		while (nodeB) {
			lenB++;
			nodeB = nodeB->next;
		}

		nodeA = headA;
		nodeB = headB;

		while (lenA > lenB) {
			lenA--;
			nodeA = nodeA->next;
		}

		while (lenA < lenB) {
			lenB--;
			nodeB = nodeB->next;
		}

		while (lenA) {
			if (nodeA == nodeB)
				return nodeA;
			lenA--;
			nodeA = nodeA->next;
			nodeB = nodeB->next;
		}
		return NULL;
	}
};

int main()
{
	Solution sln;

{
	ListNode n1(1),  n2(2),  n3(3),  n4(4),  n5(5),  n6(6),  n7(7),  n8(8); 
	ListNode m1(1),  m2(2);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;

	m1.next = &m2;
	m2.next = &n5;

	ListNode *node = sln.getIntersectionNode(&n1, &m1);
	cout << "node = " << node->val << endl;

	cout << &n1 << endl;
	cout << &n2 << endl;
	cout << &n3 << endl;
	cout << &n4 << endl;
	cout << &n5 << endl;
	cout << &n6 << endl;
	cout << &n7 << endl;
	cout << &n8 << endl;
}

{
	ListNode n1(1),  n2(2),  n3(3),  n4(4),  n5(5),  n6(6),  n7(7),  n8(8); 
	ListNode m1(1),  m2(2);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;

	ListNode *node = sln.getIntersectionNode(&n1, &n8);
	cout << "node = " << node->val << endl;
}

	return 0;
}
