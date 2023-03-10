class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Return an empty string if the input vector is empty
        if (strs.empty()) {
            return "";
        }
        // Initialize the longest common prefix to be the first string in the input vector
        string lcp = strs[0];
        // Loop over the remaining strings in the input vector, updating the longest common prefix
        for (int i = 1; i < strs.size(); i++) {
            // Check if the current string starts with the current longest common prefix
            while (strs[i].find(lcp) != 0) {
                // If not, remove the last character from the longest common prefix and try again
                lcp = lcp.substr(0, lcp.length() - 1);
            }
            // If we've reduced the longest common prefix to an empty string, there is no common prefix, so return ""
            if (lcp.empty()) {
                return "";
            }
        }
        // If we've looped over all the strings and not returned an empty string, we have the longest common prefix
        return lcp;
    }
};

// Source: https://leetcode.com/problems/longest-common-prefix/

/*
Explanation:
We exit early and return an empty string if the input vector is empty, avoiding unnecessary computation.
We initialize the longest common prefix to be the first string in the input vector, avoiding an extra initialization step and keeping memory usage low.
We use string::find to efficiently check if the current string starts with the current longest common prefix, and string::substr to remove the last character of the longest common prefix when necessary. This avoids creating new strings or using extra memory for intermediate results.
We exit early and return an empty string if we ever reduce the longest common prefix to an empty string, avoiding unnecessary computation.
*/