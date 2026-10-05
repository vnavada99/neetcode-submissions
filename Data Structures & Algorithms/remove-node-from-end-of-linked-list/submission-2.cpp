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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nNodeCount = head;
        int num = 0;
        while(nNodeCount)
        {
            nNodeCount = nNodeCount->next;
            num++;
        }
        num = num - n;

        if(num == 0)                 // removing the head
            return head->next;

        nNodeCount = head;
        while(num > 1)               // stop at the node before the target
        {
            nNodeCount = nNodeCount->next;
            num--;
        }
        nNodeCount->next = nNodeCount->next->next;
        return head;
    }
};