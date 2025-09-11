class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans, powers, precomp;
        // vec
        int j=1<<30;
        while(j>0){
            if(j > n) j/=2;
            else {
                n-=j;
                powers.push_back(j);
            }
        }
        reverse(powers.begin(), powers.end());
        long long MOD = 1e9 + 7 ;
    //     int m = powers.size();
    //     long long  a =1;
    //     precomp.push_back(1);
    //     for(int i=0 ; i<m; i++){
    //         a*=powers[i];
    //         precomp.push_back(a);
    //     }
    //     for(int i=0; i<m; i++){
    //         cout<< powers[i] << " "<<precomp[i] << "\n";
    //     }

    // //    cout<<m <<" "<< ((4>>2)&1)  <<"\n";
    //     for(int i=0; i<queries.size(); i++){
    //         int x =queries[i][1] + 1 , y = queries[i][0] ;

    //         int div = precomp[x] / precomp[ y ] ;
    //         ans.push_back(div);
    //         // cout<<x<< " "<<y<<"\n";
    //     }
        for(int i=0; i<queries.size(); i++){
            int x =queries[i][1] , y = queries[i][0] ;
            long long a =1;
            for(int i=y; i<=x; i++){
                a= (a * powers[i]) % MOD;
            }   
            ans.push_back(a);
        }

        return ans;
    }
};