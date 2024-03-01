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
    ListNode* mergelist(ListNode* left, ListNode* right){
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(left && right){
            if(left->val <= right->val){
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else{
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if(left){
            temp->next = left;
        }
        else{
            temp->next = right;
        }
        return dummynode->next;
    }
    
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = findmid(head);
        ListNode* secondhead = mid->next;
        mid->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondhead);
        return mergelist(left,right);
    }
};