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
    ListNode* deleteDuplicates(ListNode* head) {
	if (NULL == head)
		return head;

	ListNode *last_p = head;
	ListNode *p = head->next;

	while (p) {
		if (p->val == last_p->val)
			last_p->next = p->next;
		else
			last_p = p;
		p = p->next;
	}
        return head;
    }
};

int main()
{

	ListNode n1(1), n2(1), n3(1), n4(2), n5(3), n6(3);
	n1.next = &n2;
	n2.next = &n3;
	//n3.next = &n4;
	//n4.next = &n5;
	//n5.next = &n6;

	Solution sln;
	sln.deleteDuplicates(&n1);

	ListNode *p = &n1;
	while (p) {
		cout << p->val << endl;
		p = p->next;
	}

	return 0;
}
