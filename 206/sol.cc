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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next)
		return head;
	ListNode *p1, *p2, *p3;
	p1 = head;
	p2 = p1->next;
	p3 = p2->next;

	p1->next = NULL;

	while (true) {
		p2->next = p1;
		p1 = p2;
		if (p3) {
			p2 = p3;
			p3 = p3->next;
		} else
			return p2;
	}
    }
};

int main()
{
	Solution sln;
{
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	ListNode *node = sln.reverseList(&n1);
	while (node) {
		cout << node->val << "  ";
		node = node->next;
	}
	cout << endl;
}

	return 0;
}
