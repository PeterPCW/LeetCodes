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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* curr = result; // Set curr at the head of result that we just created
        int carry = 0; // Initialize carry to 0, for sums >=10
        while (l1 || l2 || carry) { // If there is a value left in l1, l2, or the carry...
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // Add the values that do exist...
            carry = sum / 10; // Set the new carry
            curr->next = new ListNode(sum % 10); // Create a node and add it to the end of result to store the current remainder after divide by tem (sum's ones place)
            curr = curr->next; // Move to the new node for the next iteration
            l1 = l1 ? l1->next : nullptr; // If l1 is not already null then move to the next node
            l2 = l2 ? l2->next : nullptr; // Same for l2
        }
        return result->next; // Return the head of result
    }
};

// Source: https://leetcode.com/problems/add-two-numbers/ 

/*
Explanation:
We create a new linked list result and initialize a pointer to point to the head of result.
We initialize a carry variable to 0.
We loop over the linked lists until we reach the end of both lists and there is no carry left.
We add the corresponding digits from l1 and l2, along with the carry, and store the result in the sum variable.
We compute the carry for the next iteration by dividing the sum by 10.
We create a new linked list node with the remainder of the sum (i.e., sum % 10), and add it to the result list.
We update the curr pointer to point to the new node we just created.
We advance the l1 and l2 pointers to the next nodes in their respective lists (if they are not already at the end).
After the loop, we return the head of the result list (i.e., result->next).
*/