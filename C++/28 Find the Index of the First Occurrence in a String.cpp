class Solution {
public:
    int strStr(string haystack, string needle) {
        //Get string lengths
        int h = haystack.length();
        int n = needle.length();
        if (n == 0) { // If needle is empty then return 0
            return 0;
        }
        if (h == 0 || h < n) { // If haystack is empty or shorter than needle...
            return -1; // needle can't be a substring in haystack
        }
        int hi = 0, ni = 0, result = -1; // Three new ints for iterating through the strings and storing the result
        while (hi < h) { // Iterate through the length of haystack...
            if (haystack[hi] == needle[ni]) { // If the current characters match then step both pointers forward
                hi++;
                ni++;
            } else { // Otherwise, reset the needle pointer to its start, and jump the haystack pointer to the next possble substring start
                hi = hi - ni + 1; // The haystack pointer needs to move backward to 1 after it started the last comparison, the needle pointer stores that length
                ni = 0; // Reset needle pointer to the first character
            }
            if (ni == n) { // If you reach the end of the needle string without resetting then you've found a match
                result = hi - ni; // The index will be where haystack started checking, same as the move above but without stepping forward for the next check to start
                break; // Stop checking, you found the first occurrence
            }
        }
        return result; // Initialized to -1, only set if the full substring needle is found in haystack
    }
};

// Source: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

/*
Explanation:
The strStr function first calculates the lengths of the two strings and checks for special cases such as an empty needle or a haystack whose length is less than the length of the needle. Those can avoid looping through haystack.
It then initializes variables hi and ni which will be used to keep track of the indices in the haystack and needle respectively. It also initializes result to -1, which will be used to store the index of the first occurrence of the needle in the haystack.
The function then loops through the haystack string character by character, comparing each character with the corresponding character in the needle substring. If the characters match, then it moves to the next character in both haystack and needle. If the characters don't match, then it resets ni to 0 (the start of needle) and moves hi to the next start position in the haystack (one forward from the last start).
If the entire needle is found in the haystack, then result is updated to the starting index of the needle substring in the haystack and the loop is broken. If the needle is not found in the haystack, then result remains -1.
*/