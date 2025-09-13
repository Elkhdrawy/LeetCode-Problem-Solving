class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        // Two pointers approach: swap characters from both ends
        while (left < right) {
            // Swap characters at left and right positions
            swap(s[left], s[right]);
            
            // Move pointers toward center
            left++;
            right--;
        }
    }
};

// Alternative implementation without using swap function
class SolutionManualSwap {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Manual swap using temporary variable
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left++;
            right--;
        }
    }
};

// One-liner using STL reverse function (if allowed)
class SolutionSTL {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
