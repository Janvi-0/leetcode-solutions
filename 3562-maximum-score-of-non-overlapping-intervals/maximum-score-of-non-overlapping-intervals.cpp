class Solution {
public:
    struct State {
        long long score;
        vector<int> indices;
    };
    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
        }
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            int r = intervals[i][1];
            nxt[i] = upper_bound(starts.begin(), starts.end(), r)
                     - starts.begin();
        }
        vector<vector<State>> dp(n + 1, vector<State>(5));
        for (int k = 0; k <= 4; k++) {
            dp[n][k] = {0, {}};
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= 4; k++) {
                State skip = dp[i + 1][k];
                State best = skip;
                if (k > 0) {
                    State take = dp[nxt[i]][k - 1];
                    take.score += intervals[i][2];
                    take.indices.push_back(intervals[i][3]);
                    sort(take.indices.begin(), take.indices.end());
                    if (better(take, best)) {
                        best = take;
                    }
                }
                dp[i][k] = best;
            }
        }
        return dp[0][4].indices;
    }
};