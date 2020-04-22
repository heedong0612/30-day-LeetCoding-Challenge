// Donghee Lee
// 4/21/2020

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &bm) {
        vector<int> dim = bm.dimensions();
        int row = dim[0];
        int col = dim[1];
     
        bool foundOne = false;
        int minCol = col - 1;
        int prevCol = col - 1;
        
        for (int i = 0; i < row; i++) {
            for (int j = prevCol; j >= 0; j--) {
            
                if (bm.get(i, j)) {     // if it is 1 
                    minCol = min(minCol, j);
                    foundOne = true;
                } else {                // if it is 0
                    prevCol = j;
                    break;
                    
                }
            }
        }
        
        return foundOne? minCol : -1;
    }
};