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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0; // If root is null, depth is 0
        }
        if (!root->left && !root->right) {
            return 1; // A single node with no branches is depth of 1
        }
        int leftDepth = root->left ? minDepth(root->left) : INT_MAX; // Call recursively on the left subtree, if that subtree is null then set to the maximum possible value so that the minDepth returned below will be the real depth of the other leg
        int rightDepth = root->right ? minDepth(root->right) : INT_MAX; // Same for right subtree
        return 1 + min(leftDepth, rightDepth); // Result is the minimum subtree plus one for the current node
    }
};

// Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/ 

/*
Explanation:
A couple of if statements check if the tree stops on the current node, then if not the subtrees are checked recursively.
It calculates the minimum depth of the left and right subtrees. If the root has no left or right child, the corresponding subtree depth is set to INT_MAX to ensure that it is not used in calculating the minimum depth.
Finally, the function returns the minimum depth of the left and right subtrees, incremented by 1 to account for the current node.
*/