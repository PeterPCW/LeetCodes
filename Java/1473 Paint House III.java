class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        if (target > m ) { // If there aren't enough houses to reach the target it's -1
            return -1;
        }
        int price = minCost(houses, cost, m, n, target, 0, 0, 0, new Integer[m][n + 1][target + 1]); // Call into the overloaded version of minCost below to calculate the price using extra parameters for recursion
        return (price == Integer.MAX_VALUE) ? -1 : price; // Return price unless it is still the initialized max value in which case return -1 because a neighborhood pattern to match target wasn't found
    }
    public int minCost(int[] houses, int[][] cost, int m, int n, int target, int neighborhoods, int prevColor, int i, Integer[][][] allPrices) { // Overloaded version of minCost above with extra inputs for a count of neighborhoods, a pointer to step through houses, and a table of all calculated prices to build over the recursions and prevent re-calculating the same paint scheme
        if (neighborhoods > target) {
            return Integer.MAX_VALUE; // If the count of neighborhoods passed > target then this paint scheme is invalid
        }
        if (i == m) { // If you have iterated through all of the houses already...
            return (neighborhoods == target) ? 0 : Integer.MAX_VALUE; // Return 0 for a hit target or a max value for a miss
        }
        if (allPrices[i][prevColor][neighborhoods] != null) { // If the current paint scheme was already calculated...
            return allPrices[i][prevColor][neighborhoods]; // Return it instead of recalcuating
        }
        int minPrice = Integer.MAX_VALUE; // Initialize a store for the current minimum price at the max so any new value will be saved over it
        if (houses[i] == 0) { // If the current house is unpainted
            for (int j = 0; j < n; j++) { // Iterate over the paint colors
                  int newNeighborhoods = (prevColor == j + 1) ? neighborhoods : neighborhoods + 1; // Pick the count of neighborhoods to pass down recursively by determining if the next color already matches the previous house and will join that neighborhood
                  int price = minCost(houses, cost, m, n, target, newNeighborhoods, j + 1, i + 1, allPrices); // Call minCost recursively with the recalculated neighborhoods and the house/color incremented
                  if (price != Integer.MAX_VALUE) { // If price returned a real value...
                      minPrice = Math.min(minPrice, cost[i][j] + price); // Return that price plus the current house cost unless it's higher than the previous minPrice
                  }
            }
        } else { // If the current house is already painted...
            int newNeighborhoods = (houses[i] == prevColor) ? neighborhoods : neighborhoods + 1; // Calculated the neighborhoods to pass by determining if the current one continues the previous color (and neighborhood) or not...
            minPrice = Math.min(minPrice, minCost(houses, cost, m, n, target, newNeighborhoods, houses[i], i + 1, allPrices)); // Then do the same recursive/minPrice check but without the need to store and add cost[i][j] since the current house won't be repainted
        }
        return allPrices[i][prevColor][neighborhoods] = minPrice; // Store the new price you calculated in allPrices and return it
    }
};

// Source: https://leetcode.com/problems/paint-house-iii/description/ 

/*
Explanation:
The function first checks if it is possible to paint the houses in such a way that there are exactly target neighborhoods. If not, it returns -1.
The minCost function is overloaded to allow for recursion and to keep all of the calculated prices as it goes to avoid any re-calculating.
A few checks can break out of the recursive iterations if the current paint scheme exceeds the target, matches it, or was already tried and saved.
If not, then for the current house all of the color options are tested to see which would create the right neighborhood count for the lowest price. This will test many more scenarios of neighborhood subsets.
After each calculation the minPrice could be updated if the new calculation is lower. Either way the cost of the current painting scheme is stored in allPrices to avoid re-calculation as mentioned above. That value is also returned to represent the minimum for the rest of the neighborhood when using a specific color on the current house, and that way the minPrice eventually becomes the cost for the full neighborhood.
*/