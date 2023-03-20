class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for (int i = 0; i < flowerbed.length; i++) { // Loop through ever spot in the flower bed...
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) { // If the current spot is open AND (it's the first plot OR the previous is empty) AND (it's the last plot OR the next one is empty)...
                flowerbed[i] = 1; // "Plant a flower" to prepare for the next iteration...
                n--; // And decreemnt the number of flowers left to plant
            }
        }
        return n <= 0; // If the number of flowers left to plant has reached/passed 0 then there were enough plots available
    }
}

// Source: https://leetcode.com/problems/can-place-flowers/ 

/*
Explanation:
Iterate over the flowerbed array to analyze each plot.
The solution is quite simple but requires some logic to deem each plot as plantable. The if statement handles the 3 conditions for allowing a new flower: a) not already planted, b) no flower directly before, and c) no flower directly after.
Modifying current plot in flowerbed[] sets the new state for the next plot check.
Using decrement on n instead of maintaining a separate count to compare saves memory at runtime (and a line of code). If enough plots are available, n will be decremented to 0 or lower.
*/