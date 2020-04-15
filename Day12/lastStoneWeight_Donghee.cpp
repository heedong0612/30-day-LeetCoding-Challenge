// 4/12/2020
// Donghee Lee

class Solution {
public:

    // Using a max heap
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> maxHeap;
        
        for (int st : stones) 
            maxHeap.push(st);
        
        int s1;
        int s2;
        
        while (maxHeap.size() > 1) {
            s1 = maxHeap.top();
            maxHeap.pop();
            s2 = maxHeap.top();
            maxHeap.pop();
            
            if (s1 != s2) {
                if (s1 > s2) {
                    maxHeap.push(s1 - s2);
                } else {
                    maxHeap.push(s2 - s1);
                }
            }
        }
        
        return maxHeap.empty()? 0 : maxHeap.top();
    }
};