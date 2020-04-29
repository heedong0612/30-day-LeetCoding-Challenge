// Donghee Lee
// 04//28/2020 

class FirstUnique {
private:
    unordered_map<int, int> cache;  
    // key: all values, val: count of the value
    // key is unique if the value is 1
    
    queue<int> v; 
    // actual queue
    
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {        
        while (!v.empty()) {
            if (cache.find(v.front()) != cache.end() && cache[v.front()] == 1) {
                return v.front();
            } else { 
                // if count is more than 1, then delete it 
                // because there is no delete function in this class and it will never be unique
                v.pop();
            }
        }
        return -1;
    }
    
    void add(int n) {
        v.push(n);
        cache[n]++;
    }
};


/*

runtime: 600ms (slow)

class FirstUnique {
private:
    unordered_map<int, list<int>::iterator> cache;  
    // key: unique values, val: iterator to the place in the list of unique values
    
    queue<int> q; 
    // actual queue
    
    list<int> ulist; 
    // current list of uniuqe values in order of the queue
    
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        if (ulist.size() == 0) return -1;
        return ulist.front();
    }
    
    void add(int n) {
        q.push(n);
         if (cache.find(n) == cache.end()) { // new unique value
            ulist.push_back(n);
            cache[n] = --ulist.end(); // iterator to the latest value pushed back to the ulist

        } else { // redundant value
      //      cout << "redundant: " << n << endl;
            if (cache[n] != ulist.end()) { // already been deleted
                ulist.erase(cache[n]);
                cache[n] = ulist.end();
            }
        }
    }
};
*/
/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */