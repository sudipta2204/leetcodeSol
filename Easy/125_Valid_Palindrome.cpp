/*
 * Problem #125: Valid Palindrome
 * Difficulty: Easy
 *
 * ----- Description -----
 *
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 *  
 * Example 1:
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric characters.
 * Since an empty string reads the same forward and backward, it is a palindrome.
 * 
 * 
 *  
 * Constraints:
 * 
 * 
 * 	1 <= s.length <= 2 * 105
 * 	s consists only of printable ASCII characters.
 *
 * ----- Solution -----
 */

class Solution {
public:

    bool isAlphanumeric(char ch){
            if('A'<=ch && ch<='Z')
            return true;
            if('a'<=ch && ch<='z')
            return true;
            if('0'<=ch && ch<='9')
            return true;
            else
            return false;
            
        }


    bool isPalindrome(string s) {
        int start=0;
        int end= s.length()-1;

        while(start<end){
        if (!isAlphanumeric(s[start])){
            start++;
            continue;
        }
        if (!isAlphanumeric(s[end])){
            end--;
            continue;
        }


        if(tolower(s[start])!=tolower(s[end])){
            return false;
        }

            start++;
            end--;
        }
        return true;
    }
};