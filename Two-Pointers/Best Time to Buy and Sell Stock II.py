class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Whenever possible to make a profit
        # perform the transaction
        # Otherwise find a lower buying point
        # Incremental gains adds up to massive profits

        n = len(prices)
        profit = 0

        for i in range(1, n):
            if prices[i] > prices[i-1]:
                profit += (prices[i] - prices[i-1])

        return profit
