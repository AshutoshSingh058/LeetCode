class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), len = 0, zeroCount=0;
        while (r < n) {
            if (nums[r] == 0){
                zeroCount++;
                while(zeroCount > k){
                    if(nums[l]==0)zeroCount--;
                    l++;
                }
            }
            r++;
            len = max(len, r - l);
        }
        return len;
    }
};