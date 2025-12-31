class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0, prev1= nums[0], curr =0;
        int p =0, np =0;
        for(int i=1; i<nums.size(); i++){
            p = nums[i] + prev2 ;
            np = prev1;
            curr = max(p,np);
            // cout<< prev2 << prev1 << curr <<endl;
            prev2= prev1;
            prev1= curr;
        }
        return prev1;
    }
};