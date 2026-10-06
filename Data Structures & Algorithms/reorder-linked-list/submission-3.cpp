/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    void printList(ListNode* head)
    {
        cout<< "\n";
        while(head)
        {
            cout<< head->val << "\t";
            head = head->next;
        }
    }

public:
    void reorderList(ListNode* head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head->next;

        while(fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        fastptr = slowptr;
        slowptr = slowptr->next;
        fastptr->next = nullptr;
        printList(head);
        printList(slowptr);

        ListNode* ite = slowptr;
        ListNode* prev = nullptr;

        while(ite)
        {
            ListNode* tmp = ite->next;
            ite->next = prev;
            prev = ite;
            ite = tmp;
        }
        printList(head);
        printList(prev);
        // merge prev and head

        ite = prev;
        fastptr = head;
        while(ite && fastptr)
        {
            ListNode* tmp = fastptr->next;
            fastptr->next = ite;
            ListNode* tmp1 = ite->next;
            ite->next = tmp;
            ite = tmp1;
            fastptr = tmp;
        }
        
    }
};
