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
        
        bool hasLockedDescendant = false;
        function<void(int)> dfs = [&](int node) {
            vector<int> toUnlock;
            for (int child : children[node]) {
                if (locked.count(child)) {
                    hasLockedDescendant = true;
                    toUnlock.push_back(child);
                }
                dfs(child);
            }
            for (int node : toUnlock) locked.erase(node);
        };
        
        dfs(num);
        
        if (!hasLockedDescendant) return false; // Must have at least one locked descendant
        
        locked[num] = user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */