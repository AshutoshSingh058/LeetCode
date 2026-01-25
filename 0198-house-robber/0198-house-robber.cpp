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


    int rob(vector<int>& nums) {
        int sum =0, maxSum = 0, n = nums.size();
        //memoization
        vector<int> dp(n,-1);
        maxSum = func(n-1, nums, dp, 0);
        return maxSum;
    }
};