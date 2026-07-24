class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<int> present(MAXX, 0);
        for (int x : nums)
            present[x] = 1;

        vector<int> values;
        for (int i = 0; i < MAXX; i++)
            if (present[i]) values.push_back(i);

        vector<int> two(MAXX, 0);

        // All XORs of two chosen values
        for (int a : values) {
            for (int b : values) {
                two[a ^ b] = 1;
            }
        }

        vector<int> ans(MAXX, 0);

        // XOR with the third value
        for (int x = 0; x < MAXX; x++) {
            if (!two[x]) continue;
            for (int a : values) {
                ans[x ^ a] = 1;
            }
        }

        int res = 0;
        for (int x : ans)
            res += x;

        return res;
    }
};