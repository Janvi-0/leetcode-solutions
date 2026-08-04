class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if (nums.empty()) return {};
        int largest = nums[0];
        int smallest = nums[0];
        unordered_set<int> st;
        for (int x : nums) {
            largest = max(largest, x);
            smallest = min(smallest, x);
            st.insert(x);
        }
        vector<int> ans;
        for (int i = smallest; i <= largest; i++) {
            if (st.find(i) == st.end())
                ans.push_back(i);
        }
        return ans;
    }
};