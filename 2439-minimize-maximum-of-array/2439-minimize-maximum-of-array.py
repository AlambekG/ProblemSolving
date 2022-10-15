class Solution:
    def minimizeArrayValue(self, nums) -> int:
        def can(nums, m):
            for i in range(len(nums) - 1, 0, -1):
                if nums[i] > m:
                    d = nums[i] - m
                    nums[i] = m
                    nums[i - 1] += d
            return nums[0] <= m

        l = -1
        r = max(nums)

        while r - l >= 2:
            m = (l + r) // 2
            if can(list(nums), m):
                r = m
            else:
                l = m

        return r