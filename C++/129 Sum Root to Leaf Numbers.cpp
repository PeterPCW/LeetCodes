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
    int sumNumbers(TreeNode* root, int sum_so_far = 0) { // Recursive function to compute the sum of all root-to-leaf numbers in a binary tree
        if (!root) { // If root pointer is null
            return 0;
        }
        int new_sum = sum_so_far * 10 + root->val; // Use the passed sum_so_far (which will be for the 10s place and up) and the current node value to set the sum for this node
        if (!root->left && !root->right) { // If there are no left or right branches from the current node...
            return new_sum; // You have reached the end of the branches and have the correct sum
        }
        // Otherwise, go a level deeper on both sides of the tree and use sumNumbers again
        int left_sum = sumNumbers(root->left, new_sum);
        int right_sum = sumNumbers(root->right, new_sum);
        return left_sum + right_sum; // Once the recursion is done, this addition will pull all of the branches back up into a sum at the root
    }
};

// Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/ 

/*
Explanation:
The sum_so_far parameter is used to keep track of the current sum as we traverse down the tree.
The base case of the recursion is when the root is null, in which case we return 0.
Otherwise, we compute the new sum by multiplying the sum_so_far by 10 and adding the value of the current node.
If the current node is a leaf node (i.e., it has no children), we return the new sum.
Otherwise, we recursively compute the sum of the left and right subtrees, passing in the new sum as the sum_so_far parameter.
Finally, we return the sum of the left and right subtrees, which will continue to add with other branches as this cascades back up through the recursion.
*/