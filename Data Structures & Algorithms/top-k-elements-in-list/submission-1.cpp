class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // count the frequency 
        unordered_map<int, int> mp;
        for(int &num: nums){
            mp[num]++;
        }

        // create a bucket
        vector<vector<int>> bucket(n+1);
        // insert elements based on the frequency
        for(auto &pair: mp){
            int elemnt = pair.first;
            int freq = pair.second;

            bucket[freq].push_back(elemnt);
        }

        vector<int> res;
        // get the top k elements
        for(int i = n; i>= 0; i--){
            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() > 0 && k > 0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};
