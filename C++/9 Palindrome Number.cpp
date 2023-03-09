class Solution {
public:
    #include <cmath>
    bool isPalindrome(int x) {
        // If x is negative or ends with a zero (except for x = 0), it can't be a palindrome
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
    
        int reversed = 0;
        
        // Reverse the digits of x until the reversed value becomes greater than or equal to x
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // If x has an odd number of digits, we can ignore the middle digit
        return x == reversed || x == reversed / 10;
    }
};

// Source: https://leetcode.com/problems/palindrome-number/

/*
Explanation:
The function takes an integer x as input and returns a boolean value indicating whether x is a palindrome or not.
The first condition checks if the number is negative or if it ends with a zero (except for x = 0), as those numbers can't be palindromes.
The reversed variable is used to keep track of the reversed value of x. We start with a value of zero.
We then use a loop to reverse the digits of x until the reversed value becomes greater than or equal to x.
Inside the loop, we multiply the current value of reversed by 10 and add the last digit of x to it. We then remove the last digit from x using integer division.
Finally, we check if x is equal to reversed or if x is equal to reversed with the middle digit removed (if x has an odd number of digits). If either of these conditions is true, we return true, indicating that x is a palindrome. Otherwise, we return false.
*/