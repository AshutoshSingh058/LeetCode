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
        vector<vector<int>> dp(n, vector<int> (totSum/2 + 1, -1));

        return func(n-1, nums, dp, totSum/2);
    }
};