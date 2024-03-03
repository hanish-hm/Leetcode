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
    ListNode* revlist(ListNode* head){
        ListNode* prev = NULL;
        ListNode* nextt;
        while(head){
            nextt = head->next;
            head->next = prev;
            prev = head;
            head = nextt;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = revlist(l1);
        ListNode* second = revlist(l2);
        int carry = 0;
        int sum;
        ListNode* dummynode = new ListNode(-1);
        ListNode* temp = dummynode;
        while(first || second){
            sum = carry;
            if(first){
                sum += first->val;
                first = first->next;
            }
            if(second){
                sum += second->val;
                second = second->next;
            }
            carry = sum/10;
            sum = sum%10;
            ListNode* newnode = new ListNode(sum);
            temp->next = newnode;
            temp = newnode;
        }
        if(carry){
            ListNode* newnode = new ListNode(carry);
            temp->next = newnode;
        }
        return revlist(dummynode->next);
    }
};