class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i;
            }
        }
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);
        
        int removeLeft = right + 1;
        int removeRight = n - left;
        int removeBoth = (left + 1) + (n - right);

        return min({removeLeft, removeRight, removeBoth});
    }
};