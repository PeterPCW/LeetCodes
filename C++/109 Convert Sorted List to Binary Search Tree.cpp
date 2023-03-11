/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0; // Initialize counter variable
        ListNode* temp = head; // Set pointer to the list head
        while (temp != nullptr) { // As long as you haven't reached the end...
            count++; // Increment the cound and...
            temp = temp->next; // Move the pointer to the next node
        }
        return buildBST(head, 0, count - 1); // Recursively build the binary search tree with the function below
    }

    TreeNode* buildBST(ListNode* head, int start, int end) {
        if (start > end) {
            return NULL; // Use null when you've reached the end on the branch
        }
        int middle = (start + end) / 2;
        ListNode* temp = head; // Set pointer to the list head
        for (int i = start; i < middle; i++) { // Find the middle of the list
            temp = temp->next; // Move the pointer to the next node until i = middle
        }
        TreeNode* root = new TreeNode(temp->val); // Start a tree at the current node
        root->left = buildBST(head, start, middle - 1); // Set the left branch to the recursively built tree before this node
        root->right = buildBST(temp->next, middle +1, end); // Set the right branch to the recursively built tree after this node
        return root; // Return the tree node for the next step in the building process
    }
};

// Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/*
Explanation:
The sortedListToBST function first counts the number of nodes in the linked list then recursively builds the balanced binary search tree using the buildBST function.
The buildBST function first calculates the midpoint of the sublist and creates a new TreeNode with the value of the corresponding linked list node.
Recursively calling buildBST on the left and right sublists, with updated start and end indices builds the branches down the tree.
Finally, it returns the root of the resulting binary search tree for the current sublist, which will be connected in the higher-level recursions.
*/