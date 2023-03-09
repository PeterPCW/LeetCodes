class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map; // Create an unordered map to store the indices of the elements.
    vector<int> result; // Create a vector to store the result.

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Find the complement of the current element.

            if (hash_map.count(complement)) { // Check if the complement already exists in the map.
                result.push_back(hash_map[complement]); // If it exists, push the index of the complement into the result vector.
                result.push_back(i); // Push the index of the current element into the result vector.
                break; // Since there is only one solution, we can exit the loop once we find it.
            }

            hash_map[nums[i]] = i; // Add the index of the current element to the map.
        }

    return result; // Return the result vector.
    }
};

// Source: https://leetcode.com/problems/two-sum/

/*
Explanation:
We start by creating an unordered map to store the indices of the elements, which will allow us to quickly check if there exists another element that adds up to the target.
We then create a vector to store the result.
We iterate over the array using a for loop, and for each element, we find the complement (the value that, when added to the current element, gives the target).
We check if the complement already exists in the map using the count function, which returns the number of elements with a given key (in this case, the complement).
If the complement exists in the map, we push the index of the complement and the current element into the result vector and exit the loop, since there is only one solution.
If the complement does not exist in the map, we add the index of the current element to the map.
Once the loop is complete, we return the result vector.
*/