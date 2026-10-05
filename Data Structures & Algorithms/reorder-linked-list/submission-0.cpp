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
            cout<< head->val<< "\t";
            head = head->next;
        }
    }
public:
    void reorderList(ListNode* head) {
        ListNode* fastptr = head->next;
        ListNode* slowptr = head;

        while(fastptr && fastptr->next)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        ListNode* secondhalf = slowptr->next;
        slowptr->next = nullptr;
        printList(secondhalf);
        printList(head);

        ListNode* prev = nullptr;

        while(secondhalf)
        {
            ListNode* tmp = secondhalf->next;
            secondhalf->next = prev;
            prev = secondhalf;
            secondhalf = tmp;
        }
        printList(prev);
        ListNode* ite = head;
        while(ite && prev)
        {
            ListNode* tmp = ite->next;
            ite->next = prev; //2 10 8
            ListNode* tmp1 = prev->next;
            prev->next = tmp;
            prev = tmp1;
            ite = tmp;
        }
    }
};
