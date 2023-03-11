class Solution {
public:
    string addBinary(string a, string b) {
        // Initialze all variables
        string result = ""; // Initialized so that it can be appended later, can't initialize in place for that (line 19)
        int carry = 0; // In case of any digits that exceed 1
        int al = a.length() - 1; // Pointer at end of a
        int bl = b.length() - 1; // Ponter at end of b
        while (al >= 0 || bl >= 0 || carry == 1) { // Loop as long as there are more digits to add or a carry-over to append
            int sum = carry;
            if (al >= 0) { // If there is still a digit in a...
                sum += a[al] - '0'; // Add it and subtract the ASCII 0 to get the numerical value instead of the ASCII value (which would be 48 too high)
                al--; // And move the pointer up one digit
            }
            if (bl >= 0) { // If there is still a digit in b...
                sum += b[bl] - 48; // Same as above but using the integer value 48 instead, this is less safe if ASCII changed somehow
                bl--; // And move the pointer up one digit
            }
            result = to_string(sum % 2) + result; // Prepend the remainder of sum/2 to the binary string
            carry = sum / 2; // Leave the quotient in carry for the next iteration, integers will discard the .5 if it exists (i.e. sum = 3)
        }
        return result; // The loop will continue until the entire new string is built, so we can return it right after
    }
};

// Source: https://leetcode.com/problems/add-binary/

/*
Explanation:
We start by initializing the result string and carry variable to 0, and the two pointers al and bl to the end of the two input strings a and b respectively.
We then loop until reaching the start of both strings and having no more carry, as we need to keep adding digits until there are no more digits in either string or there's no carry left.
We calculate the sum of the current digits and the carry, and move the al and bl pointers accordingly.
We then prepend the sum modulo 2 to the result string, and update the carry by dividing the sum by 2 (decimal points are thrown away by int).
The loop will continue until the entire new string is built, so we can return it right after.
*/