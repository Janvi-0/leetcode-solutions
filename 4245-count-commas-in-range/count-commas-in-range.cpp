class Solution {
public:
    long long countCommas(int n) {
        long long total = 0;
        long long x = 1000;
        while (x <= n) {
            total += n - x + 1;
            x *= 1000;
        }
        return total;
    }
};