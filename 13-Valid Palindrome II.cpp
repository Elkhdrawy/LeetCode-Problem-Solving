class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                // Found mismatch - try deleting either left or right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        // Already a palindrome, no deletion needed
        return true;
    }
    
private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

// Alternative: More explicit approach with deletion count
class SolutionWithCount {
public:
    bool validPalindrome(string s) {
        return canBePalindrome(s, 0, s.length() - 1, false);
    }
    
private:
    bool canBePalindrome(const string& s, int left, int right, bool deleted) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (deleted) {
                    // Already deleted one character, can't delete more
                    return false;
                }
                // Try deleting either left or right character
                return canBePalindrome(s, left + 1, right, true) || 
                       canBePalindrome(s, left, right - 1, true);
            }
            left++;
            right--;
        }
        return true;
    }
};

// Iterative approach without recursion
class SolutionIterative {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // First pass: find the first mismatch
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        
        // If no mismatch found, already a palindrome
        if (left >= right) {
            return true;
        }
        
        // Try deleting left character
        if (isPalindromeRange(s, left + 1, right)) {
            return true;
        }
        
        // Try deleting right character
        return isPalindromeRange(s, left, right - 1);
    }
    
private:
    bool isPalindromeRange(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
