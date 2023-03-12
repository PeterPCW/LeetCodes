class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1; // Only 1 way to climb 1 stair
        }
        if (n == 2) {
            return 2; // Only 2 ways to climb 2 stairs
        }
        int ways, i_1 = 2, i_2 = 1; // Initialize 3 counts we will use to calculate all of the ways iteratively
        for (int i = 3; i <= n; i++) { // Start looping at 3 since 1 and 2 are handled above and we calculate from the two previous iterations that are initialized already
            ways = i_1 + i_2; // All ways for the current count of stairs are going to be "i-1 stairs" ways adding a 1 step OR "i-2 stairs" ways with a 2 step. "i-2, 1 step, 1 step" is already counted in "i-1, 1 step".
            i_2 = i_1; // Move i-1 to i-2 for the next iteration
            i_1 = ways; // Save current ways as i-1 for the next iteration
        }
        return ways;
    }
};

// Source: https://leetcode.com/problems/climbing-stairs/

/*
Explanation:
First check if n is equal to 1 or 2, and if so, returns the corresponding base case values of 1 or 2, respectively.
If n is greater than 2, initialize the i_1 and i_2 variables to 2 and 1, respectively, since there are two distinct ways to climb the first two stairs.
Then iterate from 3 up to n, and compute the number of ways to climb i stairs by adding the number of ways to climb i-1 and i-2 stairs. Update i-1 and i-2 to prepare for the next iteration.
Finally, the method returns the value of ways, which represents the number of distinct ways to climb n stairs.
*/