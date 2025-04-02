class Solution(object):
    def maximumTripletValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        max_value = 0
        
        # Precompute the maximum value of nums[k] for k > j
        max_suffix = [0] * n
        max_suffix[-1] = nums[-1]
        for k in range(n - 2, -1, -1):
            max_suffix[k] = max(max_suffix[k + 1], nums[k])
        
        # Maintain the maximum nums[i] seen so far
        max_i = nums[0]
        
        for j in range(1, n - 1):
            value = (max_i - nums[j]) * max_suffix[j + 1]
            max_value = max(max_value, value)
            max_i = max(max_i, nums[j])
        
        return max_value
