class Solution {
public:
    
    // recursion
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size(), target);
    }
    
    int helper(vector<int>& nums, int i, int j, int& target) {
         
        if (i + 1 == j) {
            if (target == nums[i]) return i;
            return -1;
        }
        
        if (i == j){
            return -1;
        }
        
        if (nums[i] <= target && target <= nums[i + (j - i)/2 - 1]) { // sorted
            return helper(nums, i, i + (j - i)/2, target);
                
        } else if (nums[i + (j - i)/2] <= target && target <= nums[j -1]) {
            return helper(nums, i + (j - i)/2, j, target);
            
        } else {
             // any positive number would be the max
            return max(helper(nums, i, i + (j - i)/2, target),
                  helper(nums, i + (j - i)/2, j, target));
        }
    }

 
};