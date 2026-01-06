class Solution {
public:
    long long func( int i, int j, int n, vector<vector<int>>& a, vector<vector<int>> dp ){

        if ( i == n-1 ) return a[n-1][j];
        //memoization also falied here
        if(dp[i][j] != -1) return dp[i][j];

        long long d = INT_MAX , dg = INT_MAX;
        d = a[i][j] + func( i+1, j , n, a, dp);
        dg = a[i][j] + func(i+1, j+1, n, a, dp);

        return dp[i][j] = min(d, dg);
    }

    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        // memoization
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // return func(0, 0, n, a, dp);

        // tabulation
        // vector<vector<int>> dp(n, vector<int>(n,-1));
        // Space optimise
        vector<int> front(n);
        for(int j =0; j<n; j++){
            // dp[n-1][j] = a[n-1][j];
            front[j] = a[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            // for sc
            vector<int> curr(n);
            for( int j = i; j>=0; j--){
                // int d = a[i][j] + dp[i+1][j];
                int d = a[i][j] + front[j];
                // int dg = a[i][j] + dp[i+1][j+1];
                int dg = a[i][j] + front[j+1];
                
                // dp[i][j] = min(d, dg);
                curr[j] = min(d, dg);
            }
            front = curr;
        }

        return front[0];

    }
};