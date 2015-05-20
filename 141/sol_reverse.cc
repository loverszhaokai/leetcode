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

	if (NULL == head || NULL == head->next)
		return false;

	ListNode *pre_node = NULL;
	ListNode *cnt_node = head;
	ListNode *next_node = NULL;

	while (NULL != cnt_node) {
		next_node = cnt_node->next;
		cnt_node->next = pre_node;
		pre_node = cnt_node;
		cnt_node = next_node;
	}

	return pre_node == head;
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
