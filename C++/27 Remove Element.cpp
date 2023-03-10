class Solution {
public:
    int removeElement(vector<int>& nums, int val) {                
        int target = 0; // Declare an integer target to use as a pointer and initialize it to 0
        // Create a while loop that runs while target is less than the size of nums
        while (target < nums.size()) {            
            if (nums[target] == val) { // If the current element of nums is equal to val...
                nums.erase(nums.begin() + target); // Erase the target element from nums, have to provide nums.begin() for vector typing
            } else {
                target++; // Move the target to the next element
            }
        }        
        return nums.size(); // Return the final size of nums with the duplicates removed
    }
};

// Source: https://leetcode.com/problems/remove-element/

/*
Explanation:
This method takes a vector of integers called nums and an integer called val as input, and removes all occurrences of val from nums.
It does this by iterating over nums using target, and erasing any elements that are equal to val.
Finally, it returns the size of the modified nums vector.
*/