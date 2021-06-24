//Fonte:https://leetcode.com/problems/swap-nodes-in-pairs/
//Autor:Bruno Harlis
//Data: 24/06/2020

/*****************************************************************************************
* PROBLEM:
* Given a linked list, swap every two adjacent nodes and return its head. You must solve the
* problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*
* Exemple 1:
* Input: head = [1,2,3,4]
* Output: [2,1,4,3]
*
* EFFICIENCY TEST:
* Runtime: 4 ms
* Memory Usage: 7.6 MB
*****************************************************************************************/
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head)
	{
		if (head == NULL || head->next == NULL) return head;

		ListNode* x = head;
		ListNode* cabeca = new ListNode(0);
		ListNode* first = x;
		ListNode* temp;
		x = x->next;

		bool prime{ true };

		while (x != NULL)
		{
			ListNode* second = new ListNode();

			if (prime)
			{
				second = x;
				cabeca->next = second;
				prime = false;
			}
			else
			{
				temp = first;
				first = x;
				x = x->next;
				second = x;
				temp->next = second;
			}

			x = x->next;
			ListNode* third = new ListNode();
			third = x;
			second->next = first;
			first->next = third;

			if (x == NULL || x->next == NULL) break;
		}

		return cabeca->next;
	}
};



int main()
{
	ListNode* head = new ListNode(1);
	ListNode* second = new ListNode(2);
	ListNode* third = new ListNode(3);
	ListNode* fourth = new ListNode(4);
	//ListNode* fifth = new ListNode(5);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = NULL;
	//fifth->next = NULL;

	Solution s;
	ListNode* r{ s.swapPairs(head) };

	while (r != NULL)
	{
		std::cout << r->val << " ";
		r = r->next;
	}

	return 0;
}