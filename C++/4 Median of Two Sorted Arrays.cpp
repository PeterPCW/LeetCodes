class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(); // Store the size of each vector
        if (size1 > size2) { // Switch the vectors if necessary so that the shorter is the first one passed
            return findMedianSortedArrays(nums2, nums1);
        }
        int iMin = 0, iMax = size1; // Initialize pointers at the start and end of the longer vector
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2; // Store the midpoint of the current range 
            int j = (size1 + size2 + 1) / 2 - i; // Use the sizes and the midpoint above to calculate the midpoint of the shorter vector
            if (j > 0 && i < size1 && nums2[j - 1] > nums1[i]) { // If the highest value in the left half of the shorter vector is larger than the midpoint value of the longer vector...
                iMin = i + 1; // Move the range min pointer to that midpoint because the median is higher
            } else if (i > 0 && j < size2 && nums1[i - 1] > nums2[j]) { // If not, but the highest value in the left half of the longer vector is higher than the midpoint of the shorter vector...
                iMax = i - 1; // Move the range max pointer to that checked value because the median is lower
            } else { // Otherwise the current range already contains the median
                int maxLeft = 0, minRight = 0;
                if (i == 0) { // If the longer array is empty...
                    maxLeft = nums2[j - 1]; // The median is the last element of the left half of the shorter vector
                } else if (j == 0) { // If the shorter vector is empty...
                    maxLeft = nums1[i - 1]; // The median is the last element of the left half of the longer vector
                } else {
                    maxLeft = max(nums1[i - 1], nums2[j - 1]); // Otherwise the median is the maximum of the last element of the left half of the longer vector and the last element of the left half of the shorter vector
                }
                if ((size1 + size2) % 2 == 1) { // If the two vectors together are odd
                    return maxLeft; // There is no reason to calculate the other "half", left included the median as the extra odd value
                }
                if (i == size1) { // If the longer midpoint calculated out to the size of the longer vector...
                    minRight = nums2[j]; // Then all of its values were lower and the median is the first element of the shorter vector
                } else if (j == size2) { // If the shorter midpoint calculated out to the size of the shorter vector...
                    minRight = nums1[i]; // Then all of its values were lower and the median is the first element of the longer vector
                } else { // Otherwise it's a mix of each vector on each half (most likely)
                    minRight = min(nums1[i], nums2[j]); // Calculate the minimum of the right halves to mirror the max above
                }
                return (maxLeft + minRight) / 2.0; // Then average the two values to find the median
            }
        }
        return 0.0;
    }
};

// Source: https://leetcode.com/problems/median-of-two-sorted-arrays/description/ 

/*
Explanation:

*/