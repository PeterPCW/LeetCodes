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
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head || nullptr == head->next) { // If zero or one elements...
            return head; // No duplicates to remove
        }
        ListNode* skipper = head; // Start the pointer skipper at the ehad
        while (skipper != nullptr && skipper->next != nullptr) { // As long as there are current and next nodes...
            if (skipper->val == skipper->next->val) { // Check if they are equal...
                skipper->next = skipper->next->next; // And skip the next node if so
            } else { // When you find two different values...
                skipper = skipper->next; // Move the pointer as normal to the next node (skipping any that were linked past above) and continue to compare from there
            }
        }
        return head;
    }
};

// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
Explanation:
First check if the head is null or if there's only one element in the linked list. If either of these conditions is true, simply return the head.
If there are multiple elements in the linked list, start from the head and traverses the linked list.
For each node, check if the node has the same value as the next node. If so, skip the next node by setting the next pointer of the current node to the node after the compared next node, creating a bypass link instead.
If the current node and the next node have different values, move to the next node as normal and continue checking. Eventually the whole list is checked in this way and the ->next pointer will be null which exits the loop.
*/