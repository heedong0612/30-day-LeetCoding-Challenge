// 4/14/2020
// Donghee Lee

// runtime: 0 ms

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        // (1) calculate the final shift
        int shiftVal = 0;
        for (vector<int> p : shift) {
            if (p[0]) { // + 
                shiftVal += p[1];
            } else {    // -
                shiftVal -= p[1];
            }
        }
        
        // (2) get the starting point
        int len = s.length();
        int mid = ((shiftVal % len) + len) % len;
        
        // (3) fill the result string
        string result = s;
        int index = 0; // index of the string
        
        for (int i = mid; i < len; i++) {
            result[i] = s[index++]; 
        }
        
        for (int i = 0; i < mid; i++) {
            result[i] = s[index++]; 
        }
        
        return result;
    }
};