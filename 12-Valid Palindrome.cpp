class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (convert to lowercase)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

// Alternative solution: Clean string first, then check palindrome
class SolutionCleanFirst {
public:
    bool isPalindrome(string s) {
        // Step 1: Clean the string
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // Step 2: Check if cleaned string is palindrome
        int left = 0;
        int right = cleaned.length() - 1;
        
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};

// Helper function approach
class SolutionWithHelper {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            left = findNextAlnum(s, left, 1);
            right = findNextAlnum(s, right, -1);
            
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        
        return true;
    }
    
private:
    int findNextAlnum(const string& s, int start, int direction) {
        while (start >= 0 && start < s.length() && !isalnum(s[start])) {
            start += direction;
        }
        return start;
    }
};
