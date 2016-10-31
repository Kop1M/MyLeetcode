//If we can buy and sell more times, the most profit we can get is means :
//find the longest ascending series and plus them. It's greedy algorithm.
//Let's think about four digits,such as 1,6,2,7  In this part,because 2<6,so 6-1 + 7-2 is this part's max.
//every part like this is it's max.In the end, profit can get the max;
int maxProfit(vector<int>& prices) {
	if (prices.size() == 0)
		return 0;
	int buy = prices[0];
	int profit = 0;
	for (int i = 0; i+1 < prices.size(); i++){
		if (prices[i] <= prices[i + 1])
			profit += prices[i+1] - buy;
		buy = price[i+1];
	}
	return profit;
}