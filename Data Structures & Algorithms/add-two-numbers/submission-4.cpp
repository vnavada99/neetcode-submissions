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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* lsave = l1;
        ListNode* mainPrev = l1;
        while(l1 && l2)
        {
            l1->val = l1->val + l2->val + carry;
            carry = 0;
            if(l1->val > 9)
            {
                carry = (l1->val)/10;
                l1->val = (l1->val)%10;
            }
            mainPrev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(carry)
        { 
            if(l1)
            {
                ListNode* prev = l1;
                while(carry && l1)
                {
                    l1->val = l1->val+carry;
                    carry = l1->val/10;
                    l1->val = l1->val%10;
                    prev = l1;
                    l1 = l1->next;
                }
                if(carry)
                {
                    ListNode* lnew = new ListNode(carry);
                    prev->next = lnew;
                }
            }
            else if(l2)
            {
                cout<<l2->val;
                l1 = mainPrev;
                ListNode* prev = l1;
                while(carry && l2)
                {
                    l2->val = l2->val + carry;
                    carry = l2->val/10;
                    l2->val = l2->val%10;
                    l1->next = l2;
                    prev = l2;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                if(carry)
                {
                    ListNode* lnew = new ListNode(carry);
                    prev->next = lnew;
                }
            }
            else
            {
                ListNode* lnew = new ListNode(carry);
                ListNode* lite = lsave;
                while(lite->next)
                {
                    lite = lite->next;
                }
                lite->next = lnew;
            }
            
        }
        if(l2)
        {
            mainPrev->next = l2;
        }
        return lsave;
    }
};
