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
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return buildBST(nums, 0, nums.size() -1); // Call into the private buildBST which takes the same vector and two pointers
        }
    private:
        TreeNode* buildBST(vector<int>& nums, int left, int right) {
            if (left > right) { // When the left pointer crosses the right pointer that branch of the tree is done
                return nullptr;
            }
            int mid = (left + right) / 2; // Store the current midpoint of the vector range left to check
            TreeNode* node = new TreeNode(nums[mid]); // Create a node at that midpoint
            node->left = buildBST(nums, left, mid - 1); // Recursively add the next node to the left using the lower half of the passed vector range (under mid)
            node->right = buildBST(nums, mid + 1, right); // Recursively add the next node to the right using the upper half of the passed vector range (over mid)
            return node; // After the recursion, return node as the root of the new tree
        }
};

// Source: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ 

/*
Explanation:
The sortedArrayToBST method ends up as just a public wrapper for buildBST. It passes the entire array to the buildBST function, along with the indices of the leftmost and rightmost elements in the array, which allow for recursively splitting it into a binary tree.
The buildBST function first checks if the leftmost index is greater than the rightmost index. If so, it returns a null pointer indicating no child on that branch.
Otherwise, it calculates the middle index of the array, creates a new TreeNode with the value of the middle element, and recursively calls itself to create the left and right subtrees of the node.
*/