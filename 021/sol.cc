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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *h = NULL;
        ListNode *p1 = l1;
	ListNode *p2 = l2;

	if (p1 && p2) {
		if (p1->val <= p2->val) {
			h = p1;
			p1 = p1->next;
		} else {
			h = p2;
			p2 = p2->next;
		}
	} else if (p1) {
		h = p1;
		p1 = p1->next;
	} else if (p2) {
		h = p2;
		p2 = p2->next;
	}

	ListNode *head = h;

	while (p1 && p2) {
		if (p1->val <= p2->val) {
			h->next = p1;
			h = p1;
			p1 = p1->next;
		} else {
			h->next = p2;
			h = p2;
			p2 = p2->next;
		}
	}

	while (p1) {
		h->next = p1;
		h = p1;
		p1 = p1->next;
	}

	while (p2) {
		h->next = p2;
		h = p2;
		p2 = p2->next;
	}

	return head;
    }
};

int main()
{
	Solution sln;

	ListNode n11(1), n12(3), n13(7);
	ListNode n21(2), n22(9), n23(10);

	n11.next = &n12;
	n12.next = &n13;

	n21.next = &n22;
	n22.next = &n23;

	ListNode *node = sln.mergeTwoLists(&n11, &n21);

	cout << "new list:" << endl;
	while (node) {
		cout << node->val << endl;
		node = node->next;
	}

	return 0;
}
