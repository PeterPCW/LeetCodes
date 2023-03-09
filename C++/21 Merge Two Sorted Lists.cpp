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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If either list is empty, return the other list
        if (!list1) return list2;
        if (!list2) return list1;
        // Initialize a new head pointer and a current pointer
        ListNode* head;
        ListNode* curr;
        // Set the head pointer to the lesser of the first nodes
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        curr = head; // Set the current pointer to the head pointer
        while (list1 && list2) { // While neither list is empty...
            if (list1->val <= list2->val) { // If the value of list1's current node is less or equal to the value of list2's current node...
                curr->next = list1; // Append list1's current node to the merged list...
                list1 = list1->next; // And advance list1's current node
            } else {
                curr->next = list2; //Otherwise, append list2's current node to the merged list...
                list2 = list2->next; // And advance list2's current node
            }
            // Advance the current pointer to the last node of the merged list
            curr = curr->next;
        }
        if (list1) { // If there are remaining nodes in list1, append them to the merged list
            curr->next = list1;
        } else { // Otherwise, append the remaining nodes inlist2 to the merged list
            curr->next = list2;
        }
        // Return the head of the merged list
        return head;
    }
};

// Source: https://leetcode.com/problems/merge-two-sorted-lists/

/*
Explanation:
The mergeTwoLists function takes in two pointers to the head nodes of two sorted linked lists and returns a pointer to the head node of the merged linked list. The function first checks if either list is empty and returns the other list if that is the case.
The function then initializes a new head pointer and a current pointer. It sets the head pointer to the lesser of the first nodes of the two lists and advances the corresponding list's current pointer.
It then enters a while loop that runs while neither list is empty. During each iteration, the function compares the values of the current nodes of the two lists. If the value of list1's current node is less than or equal to the value of list2's current node, it appends list1's current node to the merged list and advances list1's current node. Otherwise, it appends list2's current node to the merged list and advances list2's current node. It then advances the current pointer to the last node of the merged list.
After the while loop, the function checks if there are any remaining nodes in list1 or list2 and appends them to the merged list. It then returns the head of the merged list.
*/