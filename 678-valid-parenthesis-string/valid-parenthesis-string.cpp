class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;

        // Left to Right (treat * as '(')
        for (char c : s) {
            if (c == '(' || c == '*') balance++;
            else balance--;
            if (balance < 0) return false;
        }

        balance = 0;
        // Right to Left (treat * as ')')
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == ')' || c == '*') balance++;
            else balance--;
            if (balance < 0) return false;
        }

        return true;
    }
};