// 4/15/2020
// Donghee Lee

// runtime: O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        
        int tot1 = 1;
        int tot2 = 1;
        int s = nums.size();
        
        // to multiply ---> way and then <--- way
        for (int i = 0; i < s; i++) {
            // ---->
            res[i] *= tot1;
            tot1 *= nums[i];
            
            // <----
            res[s - 1 - i] *= tot2;
            tot2 *= nums[s - 1 - i];         
        }
      
        return res;
    }
    
};