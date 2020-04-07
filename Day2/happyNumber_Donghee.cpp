// Donghee Lee
// 4/2/2020

class Solution {
public:
    unordered_set<int> st;
    
    bool isHappy(int num) {
        
        int n;
        int sum = -1; // also works as the previous number
        
        while (!trueIfDup(sum)) {
            if (sum == 1) return true;
            n = sum;
            if (sum == -1) n = num; // the very first start
            sum = 0;
            
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
        }
        
        return false;
            
    }
    
    bool trueIfDup(int num) {
        if (num < -1) { // the very first start
            return false;
        }
        
        if (st.find(num) == st.end()) {
            st.insert(num);
            return false;
        }        
        return true;      
    }
    
};