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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int size = inorder.size(); // Store the size of the vectors to use for placing Start/End pointers
            if (size == 0) { // If the vector is empty then there's no need to build a tree
                return nullptr;
            }
            return buildTreeHelper(inorder, postorder, 0, size - 1, 0, size - 1); // Call the helper fucntion which can execute recursively
        }
    private:
        TreeNode* buildTreeHelper (vector<int> inorder, vector<int> postorder, int iStart, int iEnd, int pStart, int pEnd) {
            if (iStart > iEnd) {
                return nullptr;
            }
            TreeNode* root = new TreeNode(postorder[pEnd]); // Create the current node with the last node passed in postorder
            int index = iStart; // Start a pointer at the beginning of inorder
            while (index <= iEnd && inorder[index] != postorder[pEnd]) {
                index++; // Increment the pointer until the end of inorder or until the last postorder element used above is found
            }
            // Use the index to split the remaining length of inorder/postorder in two
            int leftSize = index - iStart;
            int rightSize = iEnd - index;
            // Pass those halves into recursive tree builds to create the lower branches from the current node
            root->left = buildTreeHelper(inorder, postorder, iStart, index - 1, pStart, pStart + leftSize - 1);
            root->right = buildTreeHelper(inorder, postorder, index + 1, iEnd, pEnd - rightSize, pEnd - 1);
            return root;
        }
};

// Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 

/*
Explanation:
Use a helper function buildTreeHelper that can recursively builds the binary tree by dividing the traversals into smaller segments. This allows the algorithm to avoid unnecessary copying of vectors and instead pass only the relevant indices of the vectors to each recursive call.
In buildTreeHelper the vectors are recursively split in ~half to be passed to the next level down as the left and right branches of the tree.
*/