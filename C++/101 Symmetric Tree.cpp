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
        bool isSymmetric(TreeNode* root) {
            if (!root) { // Null trees are symmetric
                return true;
            }
            return isMirror(root->left, root->right); //Using a separate private isMirror function hides its implementation details and makes it only accessible within the Solution class
        }
    private:
        bool isMirror(TreeNode* left, TreeNode* right) {
            if (!left && !right) { // A single node (two null branches) is symmetrical too
                return true;
            }
            if (!left || !right) { // And either half null alone can't be symmetrical
                return false;
            }
            if (left->val != right->val) { // Different values aren't symmetrical either
                return false;
            }
            return isMirror(left->left, right->right) && isMirror(left->right, right->left); // Use recursion to go a level deeper if none of the checks above already returned, the AND here forces it to be true all the way up and eventually return a single boolean value
        }
};

// Source: https://leetcode.com/problems/symmetric-tree/ 

 /*
Explanation:
The isMirror function recursively checks branches in mirrored positions to see if it can find any differences. All of the boolean values AND at the end so it's as simple as ensuring the branch movements match and letting the simple if statements decide the match.
*/