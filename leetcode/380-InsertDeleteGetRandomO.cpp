class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        m[val] = e.size();
        e.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int idx = m[val];
        e[idx] = e.back();
        e.pop_back();
        m[e[idx]] = idx;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return e[rand() % e.size()];
    }
private:
    vector<int> e;
    unordered_map<int, int> m;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */