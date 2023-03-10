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
        Solution(ListNode* headvalue) {
            this->head = headvalue; // Set the member variable head to the value passed in
            std::srand(std::time(nullptr)); // Seed the random number generator with the current time, but don't pass a pointer to store the result
        }
        int getRandom() {
            int count = 1; // Start the count at 1 since the first node is the starting point
            int result = head->val; // Set the result to the first node's value
            ListNode* curr = head->next; // start iterating from the second node
            while (curr) {
                count++;
                if (std::rand() % count == 0) { // Check if remainder of random number/count is 0
                    result = curr->val; // Set the current node to the value when true, happens with 1/count probability 
                }
                curr = curr->next; // Move to the next node for the while loop to continue
            }
            return result; // Return the last current value set
        }
    private:
        ListNode* head; // Create the head member variable used above, private so that the linked list is not modifiable
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// Source: https://leetcode.com/problems/linked-list-random-node/

/*
Explanation:
To generate a random node, the class iterates through the list, using a variable to keep track of the current random node. The algorithm chooses each node with equal probability by setting the current result to the node's value with probability 1/count, where count is the number of nodes seen so far. This way, each node has an equal chance of being chosen.
The program also uses the srand function from the ctime library to seed the random number generator. This ensures that the random numbers generated are truly random, and not just a sequence of pseudo-random numbers based on a deterministic seed.
The nullptr argument passed to the std::time() function means that we don't need to pass a pointer to a std::time_t object for the result to be stored in; we just want the current time value as a std::time_t.
Finally, the example usage shows how to create a new Solution object, call its getRandom function, and delete the object and list when done.
*/