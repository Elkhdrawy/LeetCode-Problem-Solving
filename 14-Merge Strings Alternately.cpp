class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int i = 0, j = 0;
        
        // Merge characters alternately while both strings have characters
        while (i < word1.length() && j < word2.length()) {
            result += word1[i++];
            result += word2[j++];
        }
        
        // Append remaining characters from word1 (if any)
        while (i < word1.length()) {
            result += word1[i++];
        }
        
        // Append remaining characters from word2 (if any)
        while (j < word2.length()) {
            result += word2[j++];
        }
        
        return result;
    }
};

// Alternative: Using single loop with max length
class SolutionSingleLoop {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int maxLen = max(word1.length(), word2.length());
        
        for (int i = 0; i < maxLen; i++) {
            if (i < word1.length()) {
                result += word1[i];
            }
            if (i < word2.length()) {
                result += word2[i];
            }
        }
        
        return result;
    }
};

// Optimized: Pre-allocate result string size
class SolutionOptimized {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        string result;
        result.reserve(len1 + len2); // Pre-allocate memory
        
        int i = 0;
        
        // Merge alternately for the common length
        int minLen = min(len1, len2);
        for (i = 0; i < minLen; i++) {
            result += word1[i];
            result += word2[i];
        }
        
        // Append remaining characters
        if (len1 > len2) {
            result += word1.substr(i);
        } else if (len2 > len1) {
            result += word2.substr(i);
        }
        
        return result;
    }
};

// Using string iterators (more C++ style)
class SolutionIterators {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        
        while (it1 != word1.end() && it2 != word2.end()) {
            result += *it1++;
            result += *it2++;
        }
        
        // Append remaining characters
        while (it1 != word1.end()) {
            result += *it1++;
        }
        while (it2 != word2.end()) {
            result += *it2++;
        }
        
        return result;
    }
};
