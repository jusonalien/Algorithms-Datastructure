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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans1 = l1;
        ListNode* ans2 = l2;
        ListNode* shit1, *shit2;
        //ListNode newnode;
        int flag = 0;
        int reg  = 0;
        while(l1 != NULL && l2 != NULL) {
            reg = l1->val + l2->val + flag;
            l1->val = l2->val = reg % 10;
            flag = reg / 10;
            shit1 = l1;
            shit2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL && l2 == NULL) {
            if(flag != 0) {
                shit1->next = new ListNode(flag);
            }
            return ans1;
        }
        if(l1 != NULL) {
            while(l1 != NULL) {
                reg = l1->val + flag;
                l1->val = reg % 10;
                flag = reg / 10;
                shit1 = l1;
                l1 = l1->next;
            }
            if(flag != 0) {
                shit1->next = new ListNode(flag);
            }
            return ans1;
        }else {
           while(l2 != NULL) {
               reg = l2->val + flag;
               l2->val = reg % 10;
               flag = reg / 10;
               shit2 = l2;
               l2 = l2->next;
           }
           if(flag != 0) {
               shit2->next = new ListNode(flag);
           }
           return ans2;
        }
        /*
        if(l1 != NULL) { // l1 is longer  than l2
            l1->val += flag;
            return ans1;
        } else { // l2 is longer or equal l1
          if(l2 != NULL) { //l2 is longer
              l2->val += flag;
          } else if (flag != 0) { //l2 is equal to l1
              l2 = new ListNode(flag);
              //new(newnode) ListNode;
              //newnode->val = flag;
              //l2->next = newnode;
              //l2 = newnode;
          }
            
            return ans2;
        }
        */
    }
};
