class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str;
        for(const string &str: strs){
            encoded_str += to_string(str.length()) + "#" + str;
        }
        return encoded_str;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string> result;
        
        int i=0;
        while(i < n){
            int pos = s.find('#', i); // find # after that i
            int len = stoi(s.substr(i, pos-i));
            string str = s.substr(pos+1, len);
            result.push_back(str);
            i = pos+1+len;
        }
        return result;
    }
};
