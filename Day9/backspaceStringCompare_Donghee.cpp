// Donghee Lee
// 4/9/2020

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1;
        stack<char> s2;
        
        for (char c : S) {
            if (c == '#') {
                if (!s1.empty()) {
                    s1.pop();
                }
            } else {
                s1.push(c);
            }
        }
        
        for (char c : T) {
            if (c == '#') {
                if (!s2.empty()) {
                    s2.pop();
                }
            } else {
                s2.push(c);
            }
        }
        
        // compare if the result is the same
        if (s1.size() != s2.size()) return false;
        
        while (!s1.empty()) {
            cout << "s1: " << s1.top() << " s2: " << s2.top() << endl;
            if(s1.top() != s2.top()) return false;
            
            s1.pop();
            s2.pop();
        }
        
        return true;
        
    }
};