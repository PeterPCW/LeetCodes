class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0; // Put the left pointer at the start of the vector
        int right = nums.size() - 1; // Put the right pointer at the end of the vector
        while (left <= right) { // Only iterate until left passes right, meaning that the whole vector has been checked
            int mid = left + (right - left) / 2; // Find the middle of the current range...
            if (nums[mid] == target) { // If the mid value is the target then you found it
                return mid;
            } else if (nums[mid] < target) { // If not, use mid to determine if the value is in the left or right half
                left = mid + 1; // When target would be in the right half, jump left past mid
            } else {
                right = mid - 1; // When target would be in the left half, jump right past mid
            }
        }
        return left; // If mid never found the target then the left pointer will be in the correct spot for inserting the target value
    }
};

// Source: https://leetcode.com/problems/search-insert-position/

/*
Explanation:
Search for a target value in a sorted array of distinct integers using the binary serach algorithm. If the target value is found in the array, the program returns its index. Otherwise, the program returns the index where the target value would be inserted to maintain the sorted order of the array.
The program defines a class Solution with a public method searchInsert that takes a reference to a vector of integers nums and an integer target. The method initializes two pointers left and right to the first and last indices of the array, respectively.
The method then enters a while loop that continues until the left pointer exceeds the right pointer.
Within each iteration of the while loop, the method calculates the middle index mid of the current range using integer division to avoid overflow errors. If the middle element of the range equals the target value, the method returns the index of the middle element.
If the middle element is less than the target value, the method adjusts the left pointer to mid + 1 to search the right half of the current range.
If the middle element is greater than the target value, the method adjusts the right pointer to mid - 1 to search the left half of the current range.
If the target value is not found in the array, the method returns the value of the left pointer, which represents the index where the target value would be inserted to maintain the sorted order of the array.
*/