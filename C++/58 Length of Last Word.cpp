class Solution {
public:
    int lengthOfLastWord(string s) {
        const std::string WHITESPACE = " \n\r\t\f\v"; // Variable with all whitespace characters
        int len = 0; // Variable to store length
        int i = s.find_last_not_of(WHITESPACE); // Pointer started at end of string but before any whitespace
        while (i >= 0 && s[i] != ' ') { // Until you find the beginning of the string or a space...
            i--; // Decriment to move the pointer one space earlier
            len++; // Count length along the way
        }
        return len; // Return length when while loop exits (start or whitespace found)
    }
};

// Source: https://leetcode.com/problems/length-of-last-word/

/*
Explanation:
Initialize a variable len to zero to store the length of the last word.
Skip all the trailing spaces by moving the index i to the last non-whitespace character using .find_last_not_of() and the string constanct WHITESPACE that is initialized with all whitespace characters.
Start iterating over the string s from the non-whitespace end.
Calculate the length of the last word by counting the number of non-space characters, until a space or the start of the string is reached.
*/