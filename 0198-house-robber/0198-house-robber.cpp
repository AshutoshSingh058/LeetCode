class Solution {
public:
    // Recursive

    int func (int i, vector<int> &v, vector<int> &dp, int sum){
        if(i<0) return sum;
        if(i==0) return sum+v[i];
        // memoization
        if(dp[i]!=-1) return dp[i] ;
        int pick =0, notpick =0;
        pick = v[i] + func(i-2, v, dp, sum);
        notpick = func(i-1, v, dp, sum);

        return  dp[i] = max(pick, notpick);
    }


    // int rob(vector<int>& nums) {
    //     int sum =0, maxSum = 0, n = nums.size();
    //     //memoization
    //     vector<int> dp(n,-1);
    //     maxSum = func(n-1, nums, dp, 0);
    //     return maxSum;
    // }

    int rob(vector<int>& nums) {
        int sum =0, maxSum = 0, n = nums.size();
        //tabulation
        vector<int> dp(n,-1);
        // dp[0] = nums[0];
        for(int i=0; i<n; i++){

            int pick =nums[i], notpick =0;
            if(i-2 >=0) pick = nums[i] + dp[i-2] ;
            if(i-1 >=0) notpick = dp[i-1] ;

            dp[i] = max(pick, notpick);
        }
        // maxSum = func(n-1, nums, dp, 0);
        // dp[n-1] = max(dp[n-1], dp[n-2]);
        for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};