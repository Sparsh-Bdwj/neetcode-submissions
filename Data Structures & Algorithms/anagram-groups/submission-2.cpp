class Solution {
public:
    // // Approach 1 best
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     unordered_map<string, vector<string>> mp;
    //     for(string str: strs){
    //         string key = str;
    //         sort(key.begin(), key.end());
    //         mp[key].push_back(str);
    //     }
    //     vector<vector<string>> res;
    //     for(auto& pair: mp){
    //         res.push_back(pair.second);
    //     }
    //     return res;
    // }

    // // Approach 2 optimal for lower case characters
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs){
            int freq[26] = {0};

            for(char ch: str){
                freq[ch - 'a']++;
            }

            string key = "";
            for(int i =0; i<26; i++){
                key+= to_string(freq[i]) + "#";
            }

            // group anagrams 
            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
