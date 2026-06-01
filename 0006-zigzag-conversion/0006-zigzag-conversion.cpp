class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        vector<string> row(numRows);

        int curr = 0;
        int dir = 1;

        for(char c : s) {

            row[curr] += c;

            curr += dir;

            if(curr == 0 || curr == numRows - 1)
                dir = -dir;
        }

        string ans = "";

        for(string r : row)
            ans += r;

        return ans;
    }
};