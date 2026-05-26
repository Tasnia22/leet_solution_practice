class Solution {
public:
    // Helper function to expand from center
    int expandFromCenter(string& s, int left, int right) {
        
        // Check:
        // 1. left >= 0
        // 2. right < s.length()
        // 3. characters are same
        
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // Length of palindrome
        return right - left - 1;
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int len1 = expandFromCenter(s, i, i);

            // Even length palindrome
            int len2 = expandFromCenter(s, i, i + 1);

            int len = max(len1, len2);

            // Update longest palindrome
            if (len > maxLen) {

                // Calculate starting index
                start = i - (len - 1) / 2;

                maxLen = len;
            }
        }

        return s.substr(start, maxLen);
    }
};