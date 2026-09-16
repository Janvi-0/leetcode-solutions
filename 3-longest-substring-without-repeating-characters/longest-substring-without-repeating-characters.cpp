class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int maxlen=0;
        unordered_map<char, int> mp;
        for(int j=0; j<s.length(); j++){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            int len = j - i + 1;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};