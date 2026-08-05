class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[node] = true;
        for (int nei : adj[node]) {
            if (!suspicious[nei]) {
                dfs(nei, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }
        // Step 1: Mark all suspicious methods
        vector<bool> suspicious(n, false);
        dfs(k, adj, suspicious);
        // Step 2: Check if any outside method invokes a suspicious one
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                // Cannot remove anything
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        // Step 3: Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }
        return ans;
    }
};