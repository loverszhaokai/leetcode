#include <climits>
#include <cmath>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::stack;
using std::string;
using std::unordered_map;
using std::vector;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	// Time  Complexcity: O(n)
	// Space Complexcity: O(1)
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)
			return NULL;

		RandomListNode *new_head = new RandomListNode(head->label);
		RandomListNode *old_node = head;
		RandomListNode *new_node = new_head;
		RandomListNode *next_old_node;

		next_old_node = old_node->next;
		old_node->next = new_node;
		new_node->next = next_old_node;
		old_node = next_old_node;

		while (old_node) {
			new_node = new RandomListNode(old_node->label);

			next_old_node = old_node->next;
			old_node->next = new_node;
			new_node->next = next_old_node;
			old_node = next_old_node;
		}

		old_node = head;
		new_node = new_head;

		while (old_node) {
			new_node = old_node->next;
			next_old_node = new_node->next;

			new_node->random = old_node->random == NULL ? NULL : (old_node->random)->next;

			old_node = next_old_node;
		}

		old_node = head;
		new_node = new_head;

		while (old_node) {
			new_node = old_node->next;
			next_old_node = new_node->next;

			old_node->next = next_old_node;
			new_node->next = next_old_node == NULL ? NULL : next_old_node->next;

			old_node = next_old_node;
		}

		return new_head;
	}
};

int main()
{
	Solution sln;

{
	RandomListNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;

	n1.random = &n3;
	n2.random = &n1;
	n3.random = &n6;
	n4.random = &n5;
	n5.random = &n5;
	n6.random = NULL;

	RandomListNode * new_head = sln.copyRandomList(&n1);
	RandomListNode * new_node = new_head;

	while (new_node) {
		cout << "label=" << new_node->label << endl;
		if (new_node->random == NULL)
			cout << "random->label=NULL" << endl;
		else
			cout << "random->label=" << new_node->random->label << endl;
		cout << endl;
		new_node = new_node->next;
	}
}

	return 0;
}
