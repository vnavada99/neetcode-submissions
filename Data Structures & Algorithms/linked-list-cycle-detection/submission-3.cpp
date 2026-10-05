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
    bool hasCycle(ListNode* head) {

        if(!head->next || !head)
        {
            return false;
        }
        ListNode* lSlowPtr = head;
        ListNode* lFastPtr = head;

        while(lFastPtr && lFastPtr->next)
        {
            lSlowPtr = lSlowPtr->next;
            lFastPtr = lFastPtr->next->next;

            if(lFastPtr == lSlowPtr)
            {
                return true;
            }
        }
        return false;
    }
};
