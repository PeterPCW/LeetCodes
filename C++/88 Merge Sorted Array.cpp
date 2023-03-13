class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1; // Initialize pointer for nums1
        int i2 = n - 1; // Initialize pointer for nums2
        int mn = m + n -1; // Initialize pointer for merged array (written to nums1)
        while (i1 >= 0 && i2 >= 0) { // While still in the bounds of the arrays...
            if (nums1[i1] > nums2[i2]) {
                nums1[mn--] = nums1[i1--]; // nums1 had the larger value to compare, save it and move on
            } else {
                nums1[mn--] = nums2[i2--]; // nums2 had the larger value
            }
        }
        while (i2 >= 0) {
            nums1[mn--] = nums2[i2--]; // Iff there is anything left in nums2 after merging through the length of nums1 then add those too
        }
    }
};

// Source: https://leetcode.com/problems/merge-sorted-array/

 /*
Explanation:
We first declare three integer variables i1, i2, and mn to keep track of the current position in nums1, nums2, and the merged array (farther into nums1), respectively. We start at the end of nums1 and nums2 and work backwards to ensure we have space in nums1 to store the merged elements.
We then use a while loop to compare the last elements of both arrays and insert the larger element into the merged array. We decrement the appropriate pointers based on which element we inserted.
After we have exhausted one of the arrays, we insert the remaining elements from the other array into the merged array. This is only necessary for nums2 because the rest of nums1 is already in place.
We then have a single sorted array in nums1 consisting of the elements from nums1 and nums2.
*/