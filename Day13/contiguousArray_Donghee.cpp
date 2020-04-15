// 4/13/20
// Donghee Lee

// beats 96.20% of cpp submissions by runtime :)

class Solution {
public:
    
    /* Using two dynamic vectors for positive and negative values */
    
    int findMaxLength(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return 0;
        vector<int> p; // positive array
        vector<int> n; // negative array
        
        p.push_back(-1);
        n.push_back(-1);
        
        int maxSize = 0;
        int val = 0;

        // for index 0
        if (nums[0]) {
            val++;
        } else {
            val--;
        }
        
        if (val < 0) {
            n.push_back(0);
        } else {
            p.push_back(0);
        }

        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i]) {
                val++;
            } else {
                val--;
            }        

            if (val > 0) { // positive vector
                if (val < p.size()) { // p[val] exists
                    maxSize = max(maxSize, i - p[val]);
                } else {
                    p.push_back(i);
                }
                
            } else {
                val *= -1;
                if (val < n.size()) { // n[val] exists
                    maxSize = max(maxSize, i - n[val]);
                } else {
                    n.push_back(i);
                }
                val *= -1;
            }
           
        }

        return maxSize;
    
    }
    
    /* Using a map */
//     int findMaxLength(vector<int>& nums) {
//         // make a map for graph
//         // y : increment value where 0 is -1 and 1 is +1
//         // x : first index
//         // find a max shaded area with the same y value
        
//         unordered_map<int, int> m;
//         m[0] = -1;
        
//         int maxSize = 0;
//         int val = 0;
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i]) {
//                 val++;
//             } else {
//                 val--;
//             }
            
//             if (m.find(val) != m.end()) {
//                 maxSize = max(maxSize, i - m[val]);
//             } else {
//                 m[val] = i;
//             }
//         }
        
//         return maxSize;
//     }
        
};
