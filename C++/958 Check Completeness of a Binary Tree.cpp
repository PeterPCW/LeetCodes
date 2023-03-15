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
    bool isCompleteTree(TreeNode* root) {
        if (!root) { // No nodes is a complete tree
            return true;
        }
        queue<TreeNode*> q; // Initialize a queue
        q.push(root); // Queue the root node
        bool foundNull = false; // Initialize a store of whether there has been a null branch yet or not
        while (!q.empty()) { // Loop through all of the queued nodes
            for (int i = 0; i < q.size(); i++) {
                auto node = q.front(); // Get the first node from the queue to check
                q.pop(); // Pop that node from the queue so the next iteration will check a new node
                if (!node) { // Check for null nodes
                    foundNull = true; // Set true if the current node is null
                } else {
                    if (foundNull) { // If a later node is checked and not null then the tree is incomplete
                        return false;
                    }
                    // Queue the two branches of the current node for later iterations
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return true; // If the while loop exits without returning then the tree is complete
    }
};

// Source: https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/ 

/*
Explanation:
The method first checks if the root node is null. If it is null, it returns true since an empty tree is considered complete.
A queue is used to perform a breadth-first search traversal of the tree. The root node is added to the queue.
A pair of while and for loops cycle through the current level of the binary tree checking for null nodes and loading the next level of branches behind the current one.
If any null node is found then set foundNull to force a return of false on any later non-null node.
If the entire tree has been traversed without encountering any incomplete level, return true, indicating that the tree is complete.
*/