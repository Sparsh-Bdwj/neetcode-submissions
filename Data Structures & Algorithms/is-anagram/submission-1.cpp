class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int charArr[26] = {0};
        for(char ch: s){
            charArr[ch-'a']++;
        }
        for(char ch: t){
            if(charArr[ch-'a']==0) return false;
            charArr[ch-'a']--;
        }
        return true;
    }
};
