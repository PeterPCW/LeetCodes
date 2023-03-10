class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array is empty or has only one element, there are no duplicates to remove
        if (nums.size() <= 1) {
            return nums.size();
        }
        // Use two pointers to keep track of the unique elements in the array
        int write = 0; // The "write" pointer will insert the unique elements at the front of the array
        for (int read = 1; read < nums.size(); read++) { // The "read" pointer will read the full array for unique values
            if (nums[read] != nums[write]) { // If the read pointer has moved to a unique element...
                nums[++write] = nums[read]; // Move the write pointer to an unwritten index and set that index to the new unique value - has to be ++write NOT write++
            } // Else, keep incrementing the read pointer with the write pointer stationary, holding the most recent value and the end of the overwritten section
        }
        // Return the count of unique elements for 'k', write pointer plus 1
        return write + 1;
    }
};

// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

/*
Explanation:
The removeDuplicates method takes a reference to a vector of integers (vector<int>& nums) as input and returns an integer (int) indicating the number of unique elements in the vector.
The method first checks if the vector is empty or has only one element, in which case there are no duplicates to remove, and returns the size of the vector (nums.size()) in such cases.
The method then initializes two pointers write and read to 0 and 1, respectively, and iterates over the vector with the read pointer.
If the element at the read pointer is different from the element at the write pointer, then the current element is unique and needs to be added to the unique elements. Then the write pointer is incremented, and the element at the read pointer is assigned to the new index of the write pointer.
The iteration continues until the read pointer reaches the end of the vector.
Finally, the method returns the number of unique elements, which is the value of the write pointer plus 1 (since the write pointer is zero-indexed).
*/