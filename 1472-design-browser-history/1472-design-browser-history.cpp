class Node{
  public:
    string data;
    Node* prev;
    Node* next;
    Node(string x){
        this->data =  x;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
Node* obj;
public:
    BrowserHistory(string homepage) {
        obj = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newnode = new Node(url);
        obj->next = newnode;
        newnode->prev = obj;
        obj = newnode;
    }
    
    string back(int steps) {
        while(steps){
            if(obj->prev){
                obj = obj->prev;
            }
            else{
                break;
            }
            steps--;
        }
        return obj->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(obj->next){
                obj = obj->next;
            }
            else{
                break;
            }
            steps--;
        }
        return obj->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */