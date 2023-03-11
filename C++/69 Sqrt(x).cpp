class Solution {
public:
    int mySqrt(int x) {
        if ( x == 0) return 0; // Square root of 0 is 0
        int left = 1, right = x, answer; // Initialize pointers at each end of 1->x, and answer so that it is returnable outside of the while loop
        while (left <= right) { // Loop until pointers cross
            answer = left + (right - left) / 2; // Set the answer to the average of the current range
            if (answer <= x / answer) { // If the average of the range is less than x divided by that average then the answer is too small...
                left = answer + 1; // Move the left pointer to jump past the current answer
            } else { // Otherwise the average is too large...
                right = answer - 1; // Move the right pointer to jump past the current answer
                answer--; // This case firing and ending the loop by moving right past left will leave answer one too high for the real result, decrement just in case and then recalculate if the loop continues
            }
        }
        return answer; // When the loop exits the answer will be correct
    }
};

// Source: https://leetcode.com/problems/sqrtx/

/*
Explanation:
The code uses a binary search algorithm to find the square root of the input number.
The left and right pointers are initialized to 1 and x respectively. The algorithm continues until the left pointer is greater than the right pointer.
The answer is calculated as the average of the left and right pointers. If answer squared is less than or equal to x, the left pointer is moved to answer + 1. Otherwise, the right pointer is moved to answer - 1.
When the calculated answer is too large it has to be decremented. This will be overwritten in the next loop iteration, but in the case where right jumps past left the loop will exit without recalculating answer, which we know is larger than sqrt(x) because we are in the else case. For that to happen and right to jump past left the answer must be exactly one too high.
*/