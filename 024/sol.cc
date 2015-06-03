#include <cmath>

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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next)
		return head;

	ListNode *new_head = head->next;
	ListNode *p0, *p1, *p2, *p3;

	p1 = head;
	p2 = p1->next;
	p3 = p2->next;
	p2->next = p1;
	p1->next = p3;

	while ((p0 = p1) && (p1 = p0->next) && (p2 = p1->next)) {
		p3 = p2->next;
		p0->next = p2;
		p2->next = p1;
		p1->next = p3;
	}

	return new_head;
    }
};

int main()
{
	Solution sln;

{
	ListNode n1(1), n2(2);
	n1.next = &n2;
	ListNode *head = sln.swapPairs(&n1);
	while (head) {
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}

{
	ListNode n1(1), n2(2), n3(3);
	n1.next = &n2;
	n2.next = &n3;

	ListNode *head = sln.swapPairs(&n1);
	while (head) {
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}

{
	ListNode n1(1), n2(2), n3(3), n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	ListNode *head = sln.swapPairs(&n1);
	while (head) {
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
}

	return 0;
}
