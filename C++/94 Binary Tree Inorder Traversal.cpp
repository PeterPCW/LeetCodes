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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; // Create the vector to store the output...
        stack<TreeNode*> nodes; // A stack to store the nodes...
        TreeNode* curr = root; // And a pointer initialized at the root passed in
        while (curr != nullptr || !nodes.empty()) { // Keep going as long as there is a current or higher node...
            while (curr != nullptr) { // And when there is a current node...
                nodes.push(curr); // Put it on the stack...
                curr = curr->left; // Before moving to the left
            } // This will reach the highest, leftmost node to start the vector with
            curr = nodes.top(); // Set cur to the top of the nodes stack (it reached a null left branch before exiting above)...
            nodes.pop(); // Pop that node from the stack...
            result.push_back(curr->val); // And push the value into the vector
            curr = curr->right; // Knowing that there was no left node (while loop above exited), Try for a right node
            // If there is no right node the left-checking while loop will skip and we will .pop() one node higher, lopping until we find a right branch to restart the attempts to move left
        }
        return result; // Eventually all nodes are pushed into result from leftmost to rightmost
    }
};

// Source: https://leetcode.com/problems/binary-tree-inorder-traversal/ 

/*
Explanation:
Inside the inorderTraversal method, we initialize a vector<int> called result to store the inorder traversal of the binary tree. We also initialize a stack<TreeNode*> called nodes to keep track of the nodes that we still need to process. We set curr to the root of the binary tree to start the traversal.
We then enter a loop that runs until either curr is nullptr and nodes is empty. Inside the loop, we first traverse as far left as possible, pushing each node we encounter onto the nodes stack. Once we reach the leftmost node, we pop it off the stack, append its value to the result vector, and then set curr to its right child. If the right child is nullptr, we continue popping nodes off the stack until we find a node with a right child that we haven't visited yet. We repeat this process until we've processed all nodes in the binary tree.
In the main function, we create a sample binary tree, create an instance of the Solution class, call its inorderTraversal method on the root of the binary tree, and print the results.
*/