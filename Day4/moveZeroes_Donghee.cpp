// Donghee Lee
// 4/4/2020

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) { 
            return;
        }
        
        int curr = 0;
        int num = 0;
        
        while (true) {
    
            while (nums[num] == 0) {
                num++;
                if (num == nums.size()) {
                    return;
                }
            }

            while (nums[curr] != 0) {
                curr++;
                num++;
                if (curr == nums.size()) {
                    return;
                }
            }

            if (num != curr) {
                //swap
                nums[curr] = nums[num];
                nums[num] = 0;
                curr++;
                if (curr == nums.size()) {
                    return;
                }
            } else {
                continue;
            }
        }
    }
};