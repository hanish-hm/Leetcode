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
    ListNode* findnthnode(ListNode* head,int k){
        int x=0;
        while(x<=k){
            x++;
            if(x==k){
                break;
            }
            head = head->next;
        }
        return head;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* tail = head;
        int n = 1;
        while(tail->next){
            n++;
            tail = tail->next;
        }
        if(k%n==0){
            return head;
        }
        k = k%n;
        tail->next = head;
        ListNode* nthnode = findnthnode(head,n-k);
        ListNode* newhead = nthnode->next;
        nthnode->next = NULL;
        return newhead;
    }
};