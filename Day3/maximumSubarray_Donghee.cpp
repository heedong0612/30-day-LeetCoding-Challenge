// Donghee Lee
// 4/3/2020

class Solution {
public:
        
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxxx;
        
        if (nums.size() > 0) {
            maxxx = nums[0];
        } else {
            return INT_MIN;
        }
        
        for (int n : nums) {
            sum += n;
            if (maxxx < sum) maxxx = sum;
            if (sum < 0) sum = 0;
        }
        
        return maxxx;
    }
    
    
/*  USING Dynamic Programming -- but takes O(n^2) */
    
//     int maxSubArray2(vector<int>& nums) {
        
//         int sum = 0;
//         int maxxx;
        
//         if (nums.size() > 0) {
//             maxxx = nums[0];
//         } else {
//             return INT_MIN;
//         }
        
//         for (int n : nums) {
//             sum += n;
//             if (maxxx < sum) maxxx = sum;
//             if (sum < 0) sum = 0;
//         }
        
//         return maxxx;
        
//         //dp takes long
//         // initialize a dp matrix
//         int size = nums.size();
//         vector<vector<int>> dp;
        
//         for (int i = 0; i < size; i++) {
//             vector<int> vec(size, 0);
//             dp.push_back(vec);
//         }
                
//         int maxxx = INT_MIN;
//         for (int i = 0; i < size; i++) {
//             dp[i][i] = nums[i];
//             maxxx = max(maxxx, dp[i][i]);
//         }
        
//         // complete the dp matrix
//         // as i go, mark the max
        
//         for (int j = 1; j < size; j++) {
//             for (int i = 0; i+j < size; i++) {
//                 dp[i][i+j] = dp[i][i+j-1] + dp[i+1][i+j] - dp[i+1][i+j-1];
//                 maxxx = max(maxxx, dp[i][i+j]);
//             }
//         }
        
//         return maxxx;
    // }
};