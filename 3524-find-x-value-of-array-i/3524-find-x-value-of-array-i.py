class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:

        ans = [0] * k
        dp = [0] * k

        for num in nums:
            new_dp = [0] * k

            # Subarray containing only num
            new_dp[num % k] += 1

            # Extend previous subarrays
            for r in range(k):
                new_rem = (r * num) % k
                new_dp[new_rem] += dp[r]

            # Add all subarrays ending here
            for r in range(k):
                ans[r] += new_dp[r]

            dp = new_dp

        return ans