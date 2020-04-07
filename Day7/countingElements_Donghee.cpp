    // without sorting, two passes
    
    int countElements(vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) return 0;
        // without sorting
        unordered_map<int, int> m;
        int count = 0;
        
        // what we need
        for (int n : arr) {
            m[n + 1]++;
        }
        
        for (int n : arr) {
            if (m[n] > 0) {
                count += m[n];
                m[n] = 0;
            }
        }
        return count;
    }
};

/*
With Sorting but one pass -- slower

class Solution {
public:
    int countElements(vector<int>& arr) {
        if (arr.size() == 0 || arr.size() == 1) return 0;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int count = 0;
        
        for (int n : arr) {
            if (m[n] > 0) {
                count += m[n];
                m[n] = 0;
            }
            m[n + 1]++;    
        }
        
        return count;
    }
};
*/