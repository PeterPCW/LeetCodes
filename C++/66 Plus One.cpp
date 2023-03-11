class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) { // Start at the final digit and iterate back toward the beginning of the vector
            digits[i]++; // Increment the current digit
            if (digits[i] < 10) { // If the current digit is still less than 10 after incrementing (no carry-over)...
                return digits; // Return the vector as-is now, there's no more incrementing to do
            } else {
                digits[i] = 0; // If it is now 10, set it as zero and let the loop continue to the next digit
            }
        } // If you make it out of the for loop without returning, then digits isn't long enough to return...
        std:vector<int> longer_digits(digits.size() + 1, 0); // Create a new vector of all zeros that is one digit longer...
        longer_digits[0] = 1; // Change the first digit to a 1 to represent the full-length carry-over...
        return longer_digits; // And return this vector instead
    }
};

// Source: https://leetcode.com/problems/plus-one/

/*
Explanation:
First get the size of the input vector and then iterate over the digits from the end of the vector to the beginning.
For each digit, it increments the digit by one and checks if the digit is less than 10. If the digit is less than 10, the method returns the original input vector since no further carry-over is needed. If the digit is equal to 10, the method sets the digit to 0 and continues to the next digit.
If the code makes it out of the for loop without returning digits then all digits were 9s.
In that case, create a new vector with size n+1, initialize all digits to 0, and set the first digit to 1. Then returns the new vector instead.
*/