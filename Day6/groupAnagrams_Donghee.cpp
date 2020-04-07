// Donghee Lee
// 4/6/2020

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key: sorted string to represent anagram patterns
        // value: original string
        
        vector<vector<string>> result;
        if (strs.size() == 0) return result;
        
        unordered_map<string, vector<string>> m;
        
        for (string theString : strs) {
            string s = theString;
            sort(s.begin(), s.end());
            m[s].push_back(theString);
            
        }
        
        for (auto iter: m) {
            result.push_back(iter.second);
        }
        
        return result;
    }

};