/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include <cstdio>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = head;
        int cnt = 0;
        while(start != NULL) {
           start = start->next;
           cnt++;
        }
        if(cnt < n) 
            return head;
        else if(cnt == n) {
            //ListNode* cmp = head;
            //free(cmp);
            head = head->next;
            return head;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        if(cnt - n == 1) {
            pre->next = cur->next;
            return head;
        }
        for(int i = 2;i <= cnt - n;++i) {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = cur->next;
        //free(start);
        return head;
    }
};
