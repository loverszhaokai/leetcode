#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

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
	map<ListNode*, int> mm;
	ListNode *node = head;
	while (NULL != node) {
		if (1 == mm[node])
			return true;
		mm[node] = 1;
		node = node->next;
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
	// n4.next = &n1;

	Solution sln;
	cout << sln.hasCycle(&n1) << endl;

	return 0;
}
