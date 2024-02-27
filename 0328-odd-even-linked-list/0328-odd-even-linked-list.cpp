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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* oddhead = head;
        ListNode* evenhead = head->next;
        ListNode* oddtail = oddhead;
        ListNode* eventail = evenhead;
        ListNode* temp = evenhead->next;
        int x=1;
        while(temp){
            if(x%2 != 0){
                oddtail->next = temp;
                oddtail = temp;
            }
            else{
                eventail->next = temp;
                eventail = temp;
            }
            x++;
            temp = temp->next;
        }
        oddtail->next = evenhead;
        eventail->next = NULL;
        head = oddhead;
        return head;
    }
};