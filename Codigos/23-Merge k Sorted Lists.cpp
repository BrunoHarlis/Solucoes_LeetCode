//Source: https://leetcode.com/problems/merge-k-sorted-lists/
//Author: Bruno Harlis
//Date: 01/06/2020

/******************************************************************************************
* PROPOSED PROBLEM
* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
* Merge all the linked-lists into one sorted linked-list and return it.
* 
* Exemple 1
* Input: lists = [[1,4,5],[1,3,4],[2,6]]
* Output: [1,1,2,3,4,4,5,6]
* 
* Example 2
* Input: lists = []
* Output: []
*
* EFFICIENCY TEST
* Runtime: 164 ms
* Memory Usage: 13 MB
*****************************************************************************************/
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == NULL)
        return l2;
    else
        if (l2 == NULL)
            return l1;

    ListNode* tail = NULL;
    ListNode* newNumber = NULL;
    ListNode* l3 = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            newNumber = l1;
            l1 = l1->next;
        }
        else
        {
            newNumber = l2;
            l2 = l2->next;
        }

        if (l3 == NULL)
            l3 = tail = newNumber;
        else
        {
            tail->next = newNumber;
            tail = tail->next;
        }
    }

    ListNode* rest;

    if (l1) rest = l1;
    else rest = l2;

    if (l3 && tail) tail->next = rest;
    else l3 = rest;

    return l3;
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
        ListNode* head = new ListNode(0);
        ListNode* l1 = head;

        if (lists.size() == 0) return l1->next;
        if(lists.size() == 1)
        {
            l1 = lists[0];
            return l1;
        }

        l1->next = lists[0];
        l1 = l1->next;

        for (int i{ 1 }; i < lists.size(); ++i)
        {
            ListNode* l2 = lists[i];
            l1 = mergeTwoLists(l1, l2);
        }

        return l1;
    }
};

ListNode* createList(int a[], int n)
{
    ListNode* head = NULL, * p = NULL;
    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            head = p = new ListNode(a[i]);
        }
        else {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

int main(int argc, char** argv)
{
    std::vector<ListNode*> v;

    int a[] = { 2 };
    int b[] = { 0 };
    int c[] = { -1 };
    ListNode* p1 = createList(a, sizeof(a) / sizeof(int));
    ListNode* p2 = createList(b, 0);
    ListNode* p3 = createList(c, sizeof(c) / sizeof(int));

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    Solution s;
    ListNode* r{ s.mergeKLists(v) };

    while (r != NULL)
    {
        std::cout << r->val << " ";
        r = r->next;
    }

    return 0;
}