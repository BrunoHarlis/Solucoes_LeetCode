//Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Author: Bruno Harlis
//Date: 31/05/2020

/******************************************************************************************
* PROPOSED PROBLEM
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
*
* Exemple 1
* Input: head = [1,2,3,4,5], n = 2
* Output: [1,2,3,5]
*
* Example 2
* Input: head = [1], n = 1
* Output: []
*
* EFFICIENCY TEST
* Runtime: 12 ms
* Memory Usage: 10.6 MB
*****************************************************************************************/
#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* p = new ListNode(0);
        p->next = head;
        int length{ 0 };
        ListNode* first = head;

        while (first != NULL)
        {
            first = first->next;
            ++length;
        }

        length -= n;
        first = p;
 
        while (length > 0)
        {
            first = first->next;
            --length;
        }
            
        first->next = first->next->next;
        return p->next;
    }
};

int main()
{
    int x{ 2 };

    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    Solution s;
    ListNode* r{s.removeNthFromEnd(head, x)};
    
    while (r != NULL)
    {
        std::cout << r->val << " ";
        r = r->next;
    }

    return 0;
}