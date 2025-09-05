class Solution {
public:
struct Comp {
    bool operator()(pair<int,int>&a, pair<int, int>&b){
        return a.first < b.first;
    }
};
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comp >pq;
        map<int, int>mp;

        for(int i=0; i<nums.size(); i++)mp[nums[i]]++;

        for(auto it: mp)pq.push({it.second, it.first});

        vector<int> v;
        for(int i=0; i<k; i++){
            int x = pq.top().second; pq.pop();
            v.push_back(x);
        }


        return v;
        
    }
};