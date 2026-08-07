class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s="";
        int i=0; 
        int j=0;
        bool select_word1=true;
        while(i<word1.length() && j<word2.length()){
            if(select_word1==true){
                s+=word1[i];
                i++;
            }
            else{
                s+=word2[j];
                j++;
            }
            select_word1 = !select_word1;
        }
        while(i<word1.length()){
            s+=word1[i];
            i++;
        }
        while(j<word2.length()){
            s+=word2[j];
            j++;
        }
        return s;
    }
};