class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        //sort it off
        sort(nums.begin(), nums.end());
        long long r = 0, l=0, res = 0, total =0;

        while( r < nums.size()) {
            total+= nums[r];
            while(nums[r]*(r-l+1) > total + k) {
                total -= nums[l];
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;

        // //trying brute
        
        // int n = nums.size();
        // map<int,int> mp ;
        // for(int i=n-1; i>=0; i--){
        //     if(mp.find(nums[i]) != mp.end()) continue;
            
        //     int c =1 , x = k, j=1, targetvalue = nums[i];
        //     // cout << targetvalue <<" "<< c << endl;
            
        //     while(x>0 && i-j >=0 && nums[i-j]+x >= targetvalue){
                        
        //         x -= (targetvalue - nums[i-j] );
        //         c++;
        //         j++;
        //     }
        //     // cout << targetvalue <<" "<< c << endl;
            
        //     mp[targetvalue] = c;
        // }

        // int ans =1;
        // for(auto it: mp) {
        //     // cout <<it.first <<" "<< it.second<<endl;
        //     ans = max(ans, it.second);
        // }

        // return ans;
    }
};







// ///
// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         //sort it off
//         sort(nums.begin(), nums.end());
        
//         //trying brute
        
//         int n = nums.size();
//         map<int,int> mp ;
//         for(int i=n-1; i>=0; i--){
//             if(mp.find(nums[i]) != mp.end()) continue;
            
//             int c =1 , x = k, j=1, targetvalue = nums[i];
//             // cout << targetvalue <<" "<< c << endl;
            
//             while(x>0 && i-j >=0 && nums[i-j]+x >= targetvalue){
                        
//                 x -= (targetvalue - nums[i-j] );
//                 c++;
//                 j++;
//             }
//             // cout << targetvalue <<" "<< c << endl;
            
//             mp[targetvalue] = c;
//         }

//         int ans =1;
//         for(auto it: mp) {
//             // cout <<it.first <<" "<< it.second<<endl;
//             ans = max(ans, it.second);
//         }

//         return ans;
//     }
// };
// ///