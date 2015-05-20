// Reference: http://stackoverflow.com/questions/2663115/how-to-detect-a-loop-in-a-linked-list

#include <iostream>

using std::cout;
using std::endl;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode() : val(0), next(NULL) {}
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
    bool hasCycle(ListNode *head) {

	if (NULL == head)
		return false;

	ListNode *p1 = head;
	ListNode *p2 = head->next;

	while (NULL != p1 && NULL != p2) {
		if (p1 == p2)
			return true;
		p1 = p1->next;
		p2 = p2->next;
		if (NULL == p2)
			return false;
		p2 = p2->next;
	}
	return false;        
    }
};

int main()
{
	ListNode n1, n2, n3, n4;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n1;

	Solution sln;
	cout << sln.hasCycle(&n1) << endl;

	return 0;
}
