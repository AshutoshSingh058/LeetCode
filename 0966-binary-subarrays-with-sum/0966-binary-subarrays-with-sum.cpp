class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(), l=0, r=0, sum=0, cnt=0;
        vector<int> pref(n+1);
        map<int, int>mp;
        for(int i=0; i<n; i++){
            pref[i+1]=pref[i]+nums[i];
        }
        for(int i=0; i<n+1; i++){
            if(pref[i]>=goal && mp.find(pref[i]-goal)!=mp.end())cnt+=mp[pref[i]-goal];
            mp[pref[i]]++;

        }
        return cnt;
    }
};