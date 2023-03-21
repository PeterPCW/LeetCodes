class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long count = 0; // int should be fine but needs to be long for the return type
        int sum = 0; // Find strings of 0s by comparing the sum of the digits over time
        HashMap<Integer, Integer> map = new HashMap<>(); // Use a hashmap to store the sums with their frequency, since repeated sums mean extra sub arrays i.e. [0,0] has three zero-filled subarrays
        map.put(0, 1); // Initialize the map with a sum of zero
        for (int i = 0; i < nums.length; i++) { // Iterate through the length of nums
            sum += nums[i]; // Add the current element to the sum
            if (nums[i] == 0) { // If the current element is 0 to sum is already in the map...
                count += map.get(sum); // Get the number of times it has occurred and add it to the sum because the count is equal to the number of extra subarrays created by one additional 0
                map.put(sum, map.get(sum) +1); // Increment the number of times that sum has been seen
            } else { // If it's a new sum...
                map.put(sum, 1); // Add it to the map
            }
        }
        return count;
    }
}

// Source: https://leetcode.com/problems/number-of-zero-filled-subarrays/ 

/*
Explanation:
This implementation uses a hash map to keep track of the running sum and its frequency. It iterates through the array, adding each element to the sum and checking if the current sum already exists in the hash map. If it does, the counter is incremented by the frequency of the current sum, and the frequency of the current sum in the hash map is incremented. If the current sum doesn't exist in the hash map, it's added with a frequency of 1. Finally, the function returns the final count of zero-filled subarrays.
*/