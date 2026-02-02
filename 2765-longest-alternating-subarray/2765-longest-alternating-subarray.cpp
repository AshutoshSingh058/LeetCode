class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = INT_MIN, j = 1, k = 2;
        int len = 1;
        for(int i = 0; i < n-1; ++i)
        {
            j = i+1;
            k = i+2;
            len = 1;
            while(true)
            {
                if(j > n-1)
                    break;
                if(nums[j]-nums[j-1] == 1)
                    ++len;
                else
                    break;
                if(k > n-1)
                    break;
                if(nums[k]-nums[j] == -1)
                    ++len;
                else
                    break;
                j+=2;
                k+=2;
            }
            maxLen = max(maxLen, len);
        }
        if(maxLen == 1) return -1;
        return maxLen;
    }
};