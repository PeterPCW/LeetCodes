class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0; // Variable to track the count of flowers you can place
        for (int i = 0; i < flowerbed.length; i++) { // Loop through ever spot in the flower bed...
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)) { // If the current spot is open AND (it's the first plot OR the previous is empty) AND (it's the last plot OR the next one is empty)...
                count++; // Increment the count because we found a viable plot...
                flowerbed[i] = 1; // And "plant a flower" to prepare for the next plot's check
            }
        }
        return count >= n; // Compare the plantable plots to the desired number of flowers to return true/false
    }
}

// Source: https://leetcode.com/problems/can-place-flowers/ 

/*
Explanation:
Iterate over the flowerbed array to analyze each plot.
The solution is quite simple but requires some logic to deem each plot as plantable. The if statement handles the 3 conditions for allowing a new flower: a) not already planted, b) no flower directly before, and c) no flower directly after.
Modifying current plot in flowerbed[] sets the new state for the next plot check.
Compare the final count with the requested n flower to provide a true/false answer.
*/