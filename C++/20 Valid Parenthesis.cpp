class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack; // Create a stack to store opening parenthesis
        // Iterate over each character in the string
        for (char c : s) { // For each character in the string
            if (c == '(' || c == '{' || c == '[') { // If the current character is (, {, or [...
                stack.push(c); // Push that character onto the stack
            } else if (c == ')' && !stack.empty() && stack.top() == '(') {
                stack.pop(); // If the current character is closing parenthesis and matches the top of the stack, pop stack
            } else if (c == '}' && !stack.empty() && stack.top() == '{') {
                stack.pop(); // If the current character is closing braces and matches the top of the stack, pop stack
            } else if (c == ']' && !stack.empty() && stack.top() == '[') {
                stack.pop(); // If the current character is closing brackets and matches the top of the stack, pop stack
            } else {
                return false; // Otherwise, string is not valid
            }
        }
        // If stack is empty, all parentheses were matched and string is valid
        return stack.empty();
    }
};

// Source: https://leetcode.com/problems/valid-parentheses/

/*
Explanation:
The isValid() function takes a string s as input and returns a boolean value indicating whether the string contains valid parentheses.
A std::stack data structure is used to keep track of opening parentheses in the string.
The function iterates over each character in the string, and if the character is an opening parentheses, it is pushed onto the stack. If the character is a closing parentheses, the function checks if it matches the top of the stack. If it does, the top of the stack is popped. If it doesn't match, the string is not valid and the function returns false.
After iterating over the entire string, if the stack is empty, all parentheses were matched and the string is valid. If the stack is not empty, there are unmatched opening parentheses and the string is not valid.
*/