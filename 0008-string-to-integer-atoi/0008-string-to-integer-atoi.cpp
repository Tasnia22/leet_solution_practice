class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long long result = 0;

        // 3. Read digits and build number
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            result = result * 10 + digit;

            // 4. Handle overflow
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * result);
    }
};