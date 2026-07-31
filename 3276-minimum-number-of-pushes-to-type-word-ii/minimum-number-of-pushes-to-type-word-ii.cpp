class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        int n = word.size();
        for(int i = 0; i < n; i++){
            mp[word[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second, it.first});
        }
        int ans = 0;
         int val = 1;
        while(!pq.empty()){
            int temp = 0;
           
            while(!pq.empty() && temp < 8){
                ans = ans + val*pq.top().first;
                temp++;
                pq.pop();
            }
            val++;
        }
        return ans;
    }
};