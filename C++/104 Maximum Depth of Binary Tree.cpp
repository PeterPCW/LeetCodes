/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) { // If root is null
            return 0;
        }
        int leftDepth = maxDepth(root->left); // Recursively dive deeper down the left branch
        int rightDepth = maxDepth(root->right); // Recursively dive deeper down the left branch
        return 1 + max(leftDepth, rightDepth); // Continually return the maximum depth as all of the recursive calls cascade back from their null ends
    }
};

// Source: https://leetcode.com/problems/maximum-depth-of-binary-tree/ 

/*
Explanation:
If the root node is null (i.e., the tree is empty), the function returns 0, as an empty tree has a maximum depth of 0.
The maxDepth function recursively calls itself on the left and right subtrees of the current root node, and stores the returned depths in leftDepth and rightDepth, respectively.
The function then returns the maximum of the two depths, plus one (to account for the current root node).
*/