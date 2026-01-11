class Solution {
public:
    bool func(int i, vector<int> & arr,vector<vector<int>> &dp, int target){
        if( target == 0) return true;
        if( i== 0 ) return bool(arr[i] == target);
        if( dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if(arr[i] <= target)take = func(i-1, arr, dp, target - arr[i] );
        bool not_take = func(i-1, arr, dp,  target) ;

        return  dp[i][target]  = (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int n =nums.size(), totSum = 0 ;
        for( int i=0; i< n; i++){
            totSum+= nums[i];
        }
        if(totSum %2) return false;
        //memoization
        int target = totSum /2;
        vector<vector<bool>> dp(n, vector<bool> (target + 1, false));

        // return func(n-1, nums, dp, totSum/2);
        for(int i=0; i< n; i++) dp [i][0] = true;
        // tabulation
        if(nums[0] <= target) dp[0][nums[0]] = true;
        for( int i = 1; i<n; i++){
            for (int t =0; t <= target; t++ ){
                bool notTake = dp[i -1][t];
                bool take = false;
                if(nums[i] <= t) take = dp[i-1][t - nums[i]];

                dp[i][t] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};