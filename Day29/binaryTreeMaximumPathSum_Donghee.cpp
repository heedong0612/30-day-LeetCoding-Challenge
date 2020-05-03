// 04/29/2020
// Donghee Lee

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        
        int currMax = root->val;     
        findMaxPathSum(root, currMax);
        
        return currMax;
    }
    
    void findMaxPathSum(TreeNode* root, int & currMax) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            currMax = max(currMax, root->val);
            return;
        }
        findMaxPathSum(root->left, currMax);
        findMaxPathSum(root->right, currMax);
        
        int L = (root->left == nullptr)? 0 : root->left->val;
        int R = (root->right == nullptr)? 0 : root->right->val;
        
        currMax = max(currMax, L + root->val + R);
        int candidate = max(L,R) + root->val;
        root->val = max(candidate, root->val);
        currMax = max(currMax, root->val);
        return;
    }
    
};