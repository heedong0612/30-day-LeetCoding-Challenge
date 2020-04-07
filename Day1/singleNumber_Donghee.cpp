// Donghee Lee
// 4/1/2020
// using bit manipulation

class Solution {
public:
    int singleNumber2(vector<int>& nums) {
        unordered_set<int> check;
        
        for (int n : nums) {
            if (check.find(n) == check.end()) {
                check.insert(n);
            } else {
                check.erase(n);
            }
        }
        
        return *check.begin();
    }
    
    int singleNumber(vector<int>& nums) {
        int c = 0;
        for (int n : nums) {
            c = c ^ n;                  // XOR
        }   
        return c;
    }
    
};     