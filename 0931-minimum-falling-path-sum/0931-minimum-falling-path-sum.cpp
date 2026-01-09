class Solution {
public:
    int func(int i, int j, int n, vector<vector<int>>& a, vector<vector<int>>& dp ){
        if(j<0 || j>=n) return 1e9;
        if(i==0) return a[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        // Memoization
        int up = a[i][j] + func(i-1, j, n, a, dp);
        int rd = a[i][j] + func(i-1, j-1, n, a, dp);
        int ld = a[i][j] + func(i-1, j+1, n, a, dp);

        return dp[i][j] = min ({up, rd, ld});
    }

    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = 1e9;
        // for(int j=0; j<n; j++){
        //     mini = min(mini, func(n-1, j, n,  a, dp));
        // }
        // return mini;

        // Tabulation
        for(int j=0; j<n; j++){
            dp[0][j] = a[0][j];
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++){

                int d = 1e7, ld = 1e7, rd = 1e7;
                d = a[i][j] + dp[i-1][j];
                if( j-1 >= 0) ld = a[i][j] + dp[i-1][j-1];
                if( j+1 < n ) rd = a[i][j] + dp[i-1][j+1];

                dp[i][j] = min({d, ld, rd});
            }
        }
         for(int j=0; j<n; j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};