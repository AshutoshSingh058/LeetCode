class Solution(object):
    def countSymmetricIntegers(self, low, high):
        count = 0
        for num in range(low, high + 1):
            s = str(num)
            if len(s) % 2 == 0:  # even number of digits
                mid = len(s) // 2
                left = sum(int(d) for d in s[:mid])
                right = sum(int(d) for d in s[mid:])
                if left == right:
                    count += 1
        return count
