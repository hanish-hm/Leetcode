/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while(temp){
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }
            else{
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
        temp = head;
        Node* dummynode = new Node(-1);
        Node* dummy = dummynode;
        while(temp){
            dummy->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            dummy = dummy->next;
        }
        return dummynode->next;
    }
};