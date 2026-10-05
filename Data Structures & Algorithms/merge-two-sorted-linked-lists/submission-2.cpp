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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 
        ListNode* lDummy = new ListNode(0);
        ListNode* lSaveDummy = lDummy;
        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                lDummy->next = list2;
                list2 = list2->next;
            }
            else
            {
                lDummy->next = list1;
                list1 = list1->next;
            }
            lDummy = lDummy->next;
        }
        if(list1)
            lDummy->next = list1;
        else
            lDummy->next = list2;

        return lSaveDummy->next;
    }
};
