int robber(vector<int>& nums) {
        int sum =0, maxSum = 0, n = nums.size();
        //tabulation 
        // vector<int> dp(n,-1);
        //sp opt
        int n1 = 0, n2 = 0;
        // dp[0] = nums[0];
        for(int i=0; i<n; i++){

            int pick =nums[i], notpick =0;
            // if(i-2 >=0) pick = nums[i] + dp[i-2] ;
            // if(i-1 >=0) notpick = dp[i-1] 
            ;
            if(i-2 >=0) pick = nums[i] + n2 ;
            if(i-1 >=0) notpick = n1 ;

            n2 = n1;
            n1 = max(pick, notpick);
        }
        // maxSum = func(n-1, nums, dp, 0);
        // dp[n-1] = max(dp[n-1], dp[n-2]);
        // for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        // return dp[n-1];
        return n1;
    }

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> v1;
        vector<int> v2;

        for( int i=0; i<n-1; i++) v1.push_back(nums[i]);
        for( int i=1; i<n; i++) v2.push_back(nums[i]);
        

        int val = robber(v1);
        int vaf = robber(v2 );

        return max(val, vaf);
    }
};