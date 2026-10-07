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
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* lTab = dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                dummy->next = l1;
                l1 = l1->next;
            }
            else
            {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        ListNode* remain = l1 ? l1 : l2 ? l2 : nullptr;

        dummy->next = remain;
        return lTab->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.empty()) return nullptr;

    for(int step = 1; step < lists.size(); step *= 2)
        for(int i = 0; i + step < lists.size(); i += 2 * step)
            lists[i] = mergeList(lists[i], lists[i + step]);

        return lists[0];
    }
};
