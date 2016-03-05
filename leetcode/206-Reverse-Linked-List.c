/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* Pre = NULL;
    struct ListNode* Cur = head;
    struct ListNode* Nex = head->next;
    
    while(Nex != NULL) {
        Cur->next = Pre;
        Pre = Cur;
        Cur = Nex;
        Nex = Nex->next;
    }
    Cur->next = Pre;
    return Cur;
}
