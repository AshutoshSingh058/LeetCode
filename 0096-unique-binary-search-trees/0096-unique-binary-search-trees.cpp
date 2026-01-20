// class Solution {
// public:
//     int func( int n,  vector<int>& v){
//         if (n<=1) return 1;
//         if(v[n]!=-1) return v[n];
//         int ans =0;
//         for( int i=1; i<=n; i++){
//             ans += func(i-1, v)*func(n-i, v);
//         }
//         return ans;
//     }
//     int numTrees(int n) {
//         vector<int> v(n+1, -1);
//         return func(n, v);
//     }
// };

class Solution {
public:
    int dp[20]{};
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n]) return dp[n];
        for(int i = 1; i <= n; i++) 
            dp[n] += numTrees(i-1) * numTrees(n-i);
        return dp[n];
    }
};