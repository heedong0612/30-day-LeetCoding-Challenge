// Donghee Lee
// 04/25/2020

class Solution {
public:
    
    // use max element as iterating through the array
    // runtime: O(n)
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int currMax = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            currMax--;
            
            if (i == nums.size() - 1) {
                return currMax >= 0;
            } 
            
            if (currMax < 0) return false;       
            currMax = max(currMax, nums[i]);
                   
        }
        return true;
    }

    
   /*  Time Limit Exceeded: 74/75 passed  */
    
//     bool canJump2(vector<int>& nums) {
//         vector<bool> canGo(nums.size(), false);
//         canGo[0] = true;
        
//         for (int i = 0; i < nums.size(); i++) {
            
//             if (canGo[i]) { 
//                 for (int j = 1; j <= nums[i]; j++) {
//                     canGo[i + j] = true;
//                     if (i + j == nums.size()) return true; 
//                 }
                
//             }
            
//         }
//         return canGo[nums.size() - 1];
//     }
    
};