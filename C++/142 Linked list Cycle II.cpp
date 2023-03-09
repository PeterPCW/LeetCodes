class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Move the slow and fast pointers until they meet
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // Cycle detected
                // Move slow to the beginning of the list
                slow = head;
                
                // Move slow and fast at the same pace until they meet at the cycle start
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        // No cycle detected
        return NULL;
    }
};

// Source: https://leetcode.com/problems/linked-list-cycle-ii/

/*
Explanation:
The method takes a pointer to the head of a linked list as input and returns a pointer to the node where the cycle starts, or NULL if there's no cycle.
The slow and fast pointers are initially set to point to the head of the list.
We then move the slow pointer one step at a time and the fast pointer two steps at a time until they meet or the fast pointer reaches the end of the list.
If the pointers meet, it means that there's a cycle in the list. We then move the slow pointer back to the beginning of the list.
We then move both the slow and fast pointers one step at a time until they meet again. The node where they meet is the start of the cycle, so we return a pointer to it.
If the pointers don't meet and the fast pointer reaches the end of the list, it means that there's no cycle in the list, so we return NULL.
*/