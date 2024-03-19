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
    ListNode* merge(ListNode* first,ListNode* second){
        ListNode* dummynode = new ListNode(-1);
        ListNode* dummy = dummynode;
        while(first && second){
            if(first->val < second->val){
                dummy->next = first;
                dummy = first;
                first = first->next;
            }
            else{
                dummy->next = second;
                dummy = second;
                second = second->next;
            }
        }
        if(first){
            dummy->next = first;
        }
        else{
            dummy->next = second;
        }
        return dummynode->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == NULL){
            return NULL;
        }
        ListNode* first = lists[0];
        for(int i =1; i<lists.size();i++){
            first = merge(first,lists[i]);
        }
        return first;
    }
};