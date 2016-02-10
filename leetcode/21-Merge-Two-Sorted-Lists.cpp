/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* ret = ans->next;
        while(l1 != NULL && l2 != NULL) {
            ans->next = new ListNode(getBigger(l1, l2));
            ans = ans->next;
        }
        if(l1 != NULL) {
            ans->next = l1;
        } else if(l2 != NULL) {
            ans->next = l2;
        }
        return ret;
    }
    */
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ans->next = l1;
        ListNode* pre = ans;
        while(l1 != NULL && l2 != NULL) {
           if(l1->val < l2->val) {
               //pre = l1;
               l1 = l1->next;
           } else {
               ListNode* node = l2->next;
               pre->next = l2;
               l2->next = l1;
               l2 = node;
           }
           pre = pre->next;
        }
        if(l2 != NULL) {
            pre->next = l2;
        }
        return ans->next;
    }
    int getBigger(ListNode* &a, ListNode* &b) {
        int Bigger;
        if(a->val < b->val) {
            Bigger = a->val;
            a = a->next;
        } else {
            Bigger = b->val;
            b = b->next;
        }
        return Bigger;
    }
};
