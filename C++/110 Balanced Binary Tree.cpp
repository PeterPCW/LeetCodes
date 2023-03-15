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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1; // Balanced if the checker below doesn't return -1
    }
private:
    int checkHeight(TreeNode* root) { // Calculate and compare the integer heights for left and right subtrees
        if (!root) { // Empty tree is balanced
            return 0;
        }
        int leftHeight = checkHeight(root->left); // Check the height of the left subtree recursively
        int rightHeight = checkHeight(root->right); // Check the height of the right subtree recursively
        if (leftHeight == -1 || rightHeight == -1) { // If either subtree is unbalanced then the whole thing is
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) { // If the two subtrees are different heights (beyond the 1 for the lowest layer) then it isn't balanced
            return -1;
        }
        return 1 + max(leftHeight, rightHeight); // Return the true height of the (sub)tree for higher-level checks
    }
};

// Source: https://leetcode.com/problems/balanced-binary-tree/ 

/*
Explanation:
checkHeight is a helper function that returns the integer height instead. This way it can be used recursively and find the max height of each half of the tree for checking balance.
When checking height, if the current node is null then it has no height. If either sub-half is unbalanced (passed up from within its recursive check) then the whole tree is as well. And if the height imbalance exceeds 1 (meaning more than just the lowest level of nodes) then that subtree is labeled as unbalanced.
These checks will cascade up and eventually return the maximum height of the tree, or -1 if the tree is unbalanced. isBalanced can simply check for that -1 to determine true/false.
*/