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
        ListNode* lstart = new ListNode();
        ListNode* ltemp = lstart;

        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                lstart->next = list2;
                list2 = list2->next;
            }
            else
            {
                lstart->next = list1;
                list1 = list1->next;
            }
            lstart = lstart->next;   
        }
        ListNode* l = list1 ? list1 : list2 ? list2 : nullptr;
        lstart->next = l;
        return ltemp->next;
    }
};
