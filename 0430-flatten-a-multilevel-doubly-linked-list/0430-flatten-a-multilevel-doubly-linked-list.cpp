/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <bits/stdc++.h>
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return NULL;
        }
        Node* curr = head;
        Node* nextt;
        stack<Node*> st;
        Node* tail;
        while(curr!=NULL){
            if(curr->child){
                if(curr->next){
                    nextt = curr->next;
                    st.push(nextt);
                    nextt->prev = NULL;
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                curr = curr->next;
            }
            else{
                tail = curr;
                curr = curr->next;
            }
        }
        while(!st.empty()){
            tail->next = st.top();
            tail->next->prev = tail;
            st.pop();
            tail = tail->next;
            while(tail->next){
                tail = tail->next;
            }
        }
        return head;
    }
};