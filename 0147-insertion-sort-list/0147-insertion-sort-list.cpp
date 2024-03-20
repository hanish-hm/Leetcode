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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ptr=head;
        ListNode *nh=NULL;
        ListNode *f=NULL;
        while(ptr!=NULL){
            f=ptr->next;
            ptr->next=NULL;
            if(nh==NULL){
                nh=ptr;
            }
            else{
                if(nh->val>ptr->val){
                    ptr->next=nh;
                    nh=ptr;
                }
                else{
                    ListNode *tem=nh;
                    while(tem->next!=NULL && tem->next->val<ptr->val){
                        tem=tem->next;
                    }
                    if(tem->next!=NULL){
                        ptr->next=tem->next;
                        tem->next=ptr;
                    }
                    else{
                        tem->next=ptr;
                    }
                }
            }
            ptr=f;
        }
        return nh;
    }
};