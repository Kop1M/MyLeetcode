//At each time, we can buy or sell, so the lowest price we can buy in i th time is min(buy,prices[i])
//and the highest profit we can get at  i th time is max(profit,prices[i]-buy)
int maxProfit(vector<int>& prices) {
	if (prices.size() == 0)
		return 0;
	int buy = prices[0];
	int profit = 0;
	for (int i = 0; i<prices.size(); i++){
		buy = min(buy, prices[i]);
		profit = max(profit, prices[i] - buy);
	}
	return profit;
}