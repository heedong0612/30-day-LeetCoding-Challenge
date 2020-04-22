// Donghee Lee
// 04/22/2020

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        
        int count = 0;
        int sum = 0;
                
        unordered_map<int, int> hmap;   // <int sum, int frequency>
        hmap[0] = 1; 
        
        for (int n : nums) {
            sum += n;
            
            if (hmap.find(sum - k) != hmap.end()) // sum - k needed to be "eliminated" from the array
                count += hmap[sum - k];

            hmap[sum]++;
        }
        
        return count;
    }
};