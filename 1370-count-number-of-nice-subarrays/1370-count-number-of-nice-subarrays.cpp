class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int l = 0, count = 0, odd = 0;

        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] % 2 == 1) odd++;

            while (odd > k) {
                if (nums[l] % 2 == 1) odd--;
                l++;
            }

            count += (r - l + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
