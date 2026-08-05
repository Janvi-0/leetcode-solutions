class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> freq;
        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto it : freq){
            if(it.second != 0) return false;
        }
        return true;
    }
};