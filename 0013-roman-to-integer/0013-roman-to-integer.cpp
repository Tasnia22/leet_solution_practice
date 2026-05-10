#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // যদি বর্তমান মান পরের মানের চেয়ে ছোট হয়, তবে বিয়োগ হবে
            if (i + 1 < n && roman[s[i]] < roman[s[i+1]]) {
                total -= roman[s[i]];
            } 
            // অন্যথায় যোগ হবে
            else {
                total += roman[s[i]];
            }
        }
        
        return total;
    }
};
