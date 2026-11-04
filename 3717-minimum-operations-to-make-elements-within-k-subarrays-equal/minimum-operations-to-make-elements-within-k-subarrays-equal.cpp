
class Solution {
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void add(int i, long long val) {
            for (++i; i <= n; i += i & -i)
                bit[i] += val;
        }

        long long query(int i) {
            long long res = 0;
            for (; i > 0; i -= i & -i)
                res += bit[i];
            return res;
        }

        // Find the 0-based index of the kth element.
        int kth(int k) {
            int idx = 0;
            int pw = 1;

            while ((pw << 1) <= n)
                pw <<= 1;

            for (; pw; pw >>= 1) {
                int nxt = idx + pw;

                if (nxt <= n && bit[nxt] < k) {
                    idx = nxt;
                    k -= bit[nxt];
                }
            }

            return idx;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(vals.begin(), vals.end(),
                               nums[i]) - vals.begin();
        }

        BIT cnt(m), sums(m);

        long long windowSum = 0;

        auto update = [&](int i, int sign) {
            cnt.add(a[i], sign);
            sums.add(a[i], 1LL * sign * nums[i]);
            windowSum += 1LL * sign * nums[i];
        };

        vector<long long> cost(n - x + 1);

        // Sliding window
        for (int i = 0; i < n; i++) {
            update(i, 1);

            if (i >= x)
                update(i - x, -1);

            if (i >= x - 1) {
                int midIdx = cnt.kth((x + 1) / 2);
                long long median = vals[midIdx];

                long long leftCount = cnt.query(midIdx + 1);
                long long leftSum = sums.query(midIdx + 1);

                long long rightCount = x - leftCount;
                long long rightSum = windowSum - leftSum;

                cost[i - x + 1] =
                    median * leftCount - leftSum +
                    rightSum - median * rightCount;
            }
        }

        // DP with space optimization
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int t = 1; t <= k; t++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = t * x; i <= n; i++) {
                curr[i] = curr[i - 1];

                curr[i] = min(
                    curr[i],
                    prev[i - x] + cost[i - x]
                );
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
