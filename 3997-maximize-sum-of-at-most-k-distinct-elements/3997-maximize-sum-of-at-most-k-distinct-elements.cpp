class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int> vec;
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> > pq;

        for( auto &it:mp){
            // cout << it.first << " " << it.second <<"\n";
            pq.push({it.first, it.second});
        }
        
        while(!pq.empty()){
            if(k>0)k--;
            else break;
            int x = pq.top().first;
            vec.push_back(x);
            pq.pop();
        }
        return vec;
    }
};