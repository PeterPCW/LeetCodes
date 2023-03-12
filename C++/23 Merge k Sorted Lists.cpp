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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            vector<int> vector; // Definte a vector of ints to store all of the node values
            for (int i = 0; i < lists.size(); i++) { // Taking each list individually...
                while (lists[i]) { // Until it reaches the end of the current list...
                    vector.push_back(lists[i]->val); //Push the current node value into vector
                    lists[i] = lists[i]->next; // And move to the next node
                } // Then move to the next list (i++) and loop again
            }
            sort(rbegin(vector),rend(vector)); // Sort vector in descending order
            ListNode* result = nullptr; // Initialize the result
            for (int i = 0; i < vector.size(); i++) { // Loop through the whole vector...
                result = new ListNode(vector[i], result); // And create new nodes with the value, linking to the pervious iteration as ->next because you are building backward to flip from descending vector to ascending result
            }
            return result;
        }
};


// Source: https://leetcode.com/problems/merge-k-sorted-lists/

/*
Explanation:
It loops over each ListNode in the vector of lists and adds its value to a new vector.
It then sorts the vector in descending order.
Now it can loop over each integer in the vector to recreate ListNode objects.
It uses the current integer as the ListNode value and the current(/previous) value of result as its next node because the vector is in descending order but the list needs to be ascending. So the list is built backward, and always has a neat pointer to next ready to go.
*/