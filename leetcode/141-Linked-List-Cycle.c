/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return false;
        
    struct ListNode* dump = head;
    
    while(dump != NULL && dump->next != NULL) {
        dump = dump->next->next;
        head = head->next;
        if(head == dump)
            return true;
    }  
    
    return false;
/*
    do {
        dump = dump->next->next;
        head = head->next;
    }while(dump != head && dump != NULL && head != NULL);

    if(dump == NULL || head == NULL)
        return false;
    if(dump == head)
        return true;
*/
}   
