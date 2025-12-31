int rob2(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int prev2 = 0, prev1= nums[0], curr =0;
    // int p =0, np =0;
    for(int i=1; i<nums.size(); i++){
        // p = nums[i] + prev2 ;
        // np = prev1;
        curr = max(nums[i] + prev2 ,prev1);
        // cout<< prev2 << prev1 << curr <<endl;
        prev2= prev1;
        prev1= curr;
    }
    return prev1;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> v1;
        vector<int> v2;
        for( int i=0; i<n; i++){
            if(i==0) v2.push_back(nums[i]);
            else if(i == n-1) v1.push_back(nums[i]);
            else {
                v1.push_back(nums[i]);
                v2.push_back(nums[i]);

            }
        }

        int val = rob2(v1);
        int vaf = rob2(v2 );

        return max(val, vaf);
    }
};