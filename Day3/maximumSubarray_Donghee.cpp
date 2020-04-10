// Donghee Lee
// 4/11/2020

class Solution {
public:
    
    /*  (1) O(n) */
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

/*  (2) Using Divide and Conquer   */
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         if (nums.size() == 1) return nums[0];

//         return dnc(nums, 0, nums.size());
//     }
    
//     int dnc(vector<int>& vec, int i, int j) {
//         if (i == j || i + 1 == j) {
//             return vec[i];
//         }
        
//         int val = cmpReturnMax(vec, i, j);
        
//         return max(val,
//                   max (dnc(vec, i, i + (j - i+1)/2),
//                        dnc(vec, i + (j - i+1)/2, j)));
//     }
    
//     int cmpReturnMax(vector<int>& vec, int i, int j) {
        
//         int mid = i + (j - i-1)/2;
//         int lmax = INT_MIN, rmax = INT_MIN;
//         int curr = 0;
        
//         for (int l = mid; l >= i; l--) {
//             curr += vec[l];
//             if (curr > lmax) lmax = curr;
//         }
        
//         curr = 0;
//         for (int r = mid + 1; r < j; r++) {
//             curr += vec[r];
//             if (curr > rmax) rmax = curr;
//         }
//       //  cout << "i: " << i << ", j: " << j << ", lmax : " << lmax << ", rmax: " << rmax << endl;
//         if (lmax == INT_MIN) return rmax;
//         if (rmax == INT_MIN) return lmax;
//         return lmax + rmax;
//     }
    
    
/*  (3) Using Dynamic Programming -- but takes O(n^2) */
    
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