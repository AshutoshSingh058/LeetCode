class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        // First pass: apply operations
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        // Second pass: shift non-zero elements to the front
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
        // Fill the remaining positions with 0's
        while (pos < n) {
            nums[pos++] = 0;
        }
        return nums;
    }
};
