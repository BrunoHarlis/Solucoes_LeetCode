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
};


int main()
{
    ListNode* head = new ListNode();
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 3;
    second->next = third;

    third->val = 5;
    third->next = NULL;

    ListNode* head2 = new ListNode();
    ListNode* second2 = new ListNode();
    ListNode* third2 = new ListNode();

    head2->val = 2;
    head2->next = second2;

    second2->val = 4;
    second2->next = third2;

    third2->val = 6;
    third2->next = NULL;

    Solution s;
    ListNode* r{s.mergeTwoLists(head, head2)};
    
    while (r != NULL)
    {
        std::cout << r->val << " ";
        r = r->next;
    }

    return 0;
}