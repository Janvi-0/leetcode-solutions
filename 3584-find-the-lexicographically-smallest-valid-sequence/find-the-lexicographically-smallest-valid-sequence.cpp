class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = the position in word1 from which
        // word2[j] can be matched as part of a suffix.
        vector<int> last(m, -1);

        // Build last[] from right to left.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        // We can use at most ONE mismatch.
        bool canSkip = true;

        j = 0;

        // Greedily construct the answer from left to right.
        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Case 1: exact match
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            }

            // Case 2: use our one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {

                canSkip = false;
                ans[j] = i;
                j++;
            }
        }

        // If we matched all of word2, return answer.
        // Otherwise no valid sequence exists.
        return j == m ? ans : vector<int>();
    }
};