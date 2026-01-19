class Solution {
public:
    
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), tot=0, s=0;

        for(int i=0; i<n; i++){
            s = 0;
            map<int, int> mp;
            for(int j=i; j<n; j++){
                s+= nums[j];
                
                mp[nums[j]]++;
                if(mp.find(s)!= mp.end()) tot++;

            }
        }
        return tot;
    }
};