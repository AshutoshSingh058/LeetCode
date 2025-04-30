class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size(), digit=0, mod=10, ans=0;

        for(int i=0; i<n;i++){
            int x=0;
            while(nums[i]>0){
                nums[i]/=mod;
                x++;
            }
            if(x%2==0)ans++;
        }
        return ans;
    }
};