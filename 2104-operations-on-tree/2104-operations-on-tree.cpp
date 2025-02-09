class LockingTree {
    vector<int> parent;
    vector<vector<int>> children;
    unordered_map<int, int> locked;
public:
    LockingTree(vector<int>& parent) : parent(parent), children(parent.size()) {
        for (int i = 1; i < parent.size(); ++i) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked.count(num)) return false;
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked.count(num) && locked[num] == user) {
            locked.erase(num);
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (locked.count(num)) return false; // Node must be unlocked
        
        int curr = num;
        while (curr != -1) {
            if (locked.count(curr)) return false; // No locked ancestors
            curr = parent[curr];
        }
        vector<int> lockeddescendants;
        int lockedcount = 0;
        if(!haslockeddescendants(num,lockeddescendants, lockedcount)){
            return false;
        }
        for(auto desc: lockeddescendants){
            locked.erase(desc);
        }
        locked[num] = user;
        return true;
    }
private:
    bool haslockeddescendants(int num, vector<int> &lockeddescendants, int& lockedcount){
        if(locked.count(num)){
            lockeddescendants.push_back(num);
            lockedcount++;
        }
        for(auto it:children[num]){
            haslockeddescendants(it,lockeddescendants, lockedcount);
        }
        return lockedcount>0;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */