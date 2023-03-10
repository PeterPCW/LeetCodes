class Solution {
    public:
        int romanToInt(string s) { // String input to the function, int output
            unordered_map<char, int> romanToIntMap{ // Map roman numerals to integer values
                {'I',1},
                {'V',5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000},
            };
            int result = 0; // Initialize result variable to store the final integer value
            int prev = 0; // Initialize previous value as 0 too
            for (char c : s) { // Iterate through each character in the string
                int curr = romanToIntMap[c]; // Get the integer value for the current character
                if (curr > prev) { //If the current value is greater than the previous value...
                    result += curr - 2*prev; // Subtract twice the previous value from the current value and add to the result
                } else { // Otherwise, add the current value to the result
                    result += curr;
                }
                prev = curr; // Set the previous value to the current value for the next iteration
            }
            return result; //Return the final integer value
        }
};

// Source: https://leetcode.com/problems/roman-to-integer/

/*
Explanation:
The romanToInt function takes a string argument s which represents a roman numeral and returns its equivalent integer value.
The function uses an unordered map romanToIntMap to map each roman numeral character to its corresponding integer value. The function initializes a result variable to store the final integer value and a previous variable to store the previous integer value.
The function then iterates through each character in the string s and gets its corresponding integer value from the romanToIntMap. If the current value is greater than the previous value, it subtracts twice the previous value from the current value and adds it to the result. Otherwise, it adds the current value to the result. The previous value is then set to the current value for the next iteration.
Finally, the function returns the final integer value.
*/