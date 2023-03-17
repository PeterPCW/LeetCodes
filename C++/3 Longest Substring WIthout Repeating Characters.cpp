class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0; // Variable to store the current max length
        int left = 0, right = 0; // Pointers for scanning through the string
        vector<bool> seen(128, false); // Create an array to store a yes/no for if a character has already been seen
        while (right < s.length()) { // Check the whole string
            if (!seen[s[right]]) { // If the current character is new...
                seen[s[right++]] = true; // Set it as seen and move to the next character
                max_len = max(max_len, right - left); // Update the max if we've found a new longest substring
            } else { // If it is a duplicate character then the left pointer moves one forward...
                seen[s[left++]] = false; // After being removed from the seen vector, since the new substring starting point (left) won't include the character at --left anymore
            }
        }
        return max_len;
    }
};

// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/ 

/*
Explanation:
The method uses a sliding window approach to solve the problem. It initializes several variables, including n, which stores the length of the input string, max_len, which stores the length of the longest substring seen so far, left and right, which represent the left and right endpoints of the current window, and seen, which is a boolean vector that stores whether a character has been seen before or not.
The method then enters a while loop that iterates through the input string. If the current character has not been seen before, it is added to the seen vector, and the right endpoint of the window is moved to the right. If the current character has been seen before, it is removed from the seen vector, and the left endpoint of the window is moved to the right.
At each iteration, the method checks whether the length of the current substring (i.e., right - left) is greater than the current max_len. If it is, max_len is updated to the new value.
*/