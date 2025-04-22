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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        
        // If we need to remove the head node
        if(cnt == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* curr = head;
        for(int i = 0; i < cnt - n - 1; i++) {
            curr = curr->next;
        }
        
        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        
        return head;
    }
};