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
ListNode* findkthnode(ListNode* temp,int k){
    int x = 1;
    while(k!=x){
        temp = temp->next;
        if(!temp){
            return NULL;
        }
        x++;
    }
    return temp;
}

void reverselist(ListNode* temp){
    ListNode* prev = NULL;
    ListNode* nextnode;
    while(temp){
        nextnode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        while(temp){
            ListNode* kthnode = findkthnode(temp,k);
            if(kthnode == NULL){
                if(prevnode){
                    prevnode->next = temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next = NULL;
            reverselist(temp);
            if(temp==head){
                head = kthnode;
            }
            else{
                prevnode->next = kthnode;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;}
};