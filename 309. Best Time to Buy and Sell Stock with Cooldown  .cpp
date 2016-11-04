/*Copy others thinking:
It is obvious that we should use dynamic programming to solve this question.
Notice that we must cooldown after we sell one stock, so it's important for us to know when we buy the stock.
Let dp[i] = The maxprofit we get in i - th day.
My dp solution is :
dp[i] = max(dp[i - 1], prices[i] - prices[j] + dp[j - 2]) for (j = 0~i - 1)
In i - th day, we scan j = 0~i - 1 to find when we buy stock,
if we buy j - th day stock, we must have a cooldown in(j - 1) - th day,
that means we can only consider dp[j - 2] if we buy stock in j - th day.
*/
int maxProfit(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;
	vector<int> dp(prices.size());
	dp[0] = 0;
	int tmpMax = -prices[0];//use tmpMax to store max profit-buy before one sell
	for (int i = 1; i < prices.size(); i++){
		dp[i] = max(dp[i], max(dp[i - 1], prices[i] + tmpMax));
		if (i >= 2)
			tmpMax = max(tmpMax, dp[i - 2] - prices[i]);
		else
			tmpMax = max(tmpMax, -prices[i]);
	}
	return dp[prices.size() - 1];
}

//author's version
int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n <= 1) return 0;
	vector<int> dp;
	dp.resize(n, 0);
	//core thinking:
	//dp[i] = max(dp[i-1], prices[i]-prices[j]+dp[j-2]); for(j=0~i)
	/* currect but too slow
	for (int i = 1; i < n; ++i) {
	int tmpmax = 0;
	for (int j = 0; j < i; ++j) {
	if (j>=2) tmpmax = dp[j-2]-prices[j];
	else tmpmax = -prices[j];
	dp[i] = max(dp[i], max(dp[i-1], prices[i]+tmpmax));
	}
	}
	*/
	//save tmpmax in one-pass 
	int tmpmax = -prices[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i], max(dp[i - 1], prices[i] + tmpmax));
		if (i >= 2) tmpmax = max(tmpmax, dp[i - 2] - prices[i]);
		else tmpmax = max(tmpmax, -prices[i]);
	}
	return dp[n - 1];
}