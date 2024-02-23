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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* temp = head;
        ListNode* nextnode;
        ListNode* todelete;
        while(temp && temp->next){
            nextnode = temp->next;
            while(nextnode && (temp->val == nextnode->val)){
                todelete = nextnode;
                nextnode = nextnode->next;
                delete todelete;
            }
            temp->next = nextnode;
            temp = temp->next;
        }
        return head;
    }
};