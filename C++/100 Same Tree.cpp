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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) { // Both null
            return true;
        }
        if ( p == nullptr || q == nullptr) { // One null, can't be the same
            return false;
        }
        if (p->val != q->val) { // The values are different so not the same
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree (p->right, q->right); // Use recursion to check the next branches down, and AND to collect all of the values in the cascade back up
    }
};

// Source: https://leetcode.com/problems/same-tree/ 

/*
Explanation:
The code checks if both pointers are null, if only one is null or if their values are different. If any of these conditions are met, the function returns false, indicating that the trees are not the same.
Otherwise, the function recursively checks the left and right subtrees of the current nodes to determine if the trees are the same.
*/