/*
   It's easy to think that we can divide the vector to two parts, and caculate their own max,and plus.
But it's time complexity is O(n2);
	Here, we use space to get less time. When we solve quetion I, we use recursion.Thus, 
	we can store every local max profit!
*/
int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	if (n < 2)
		return 0;
	vector<int> p(n, 0);
	vector<int> q(n, 0);
	for (int i = 1, valley = prices[0]; i < n; i++){
		valley = min(valley, prices[i]);
		p[i] = max(p[i - 1], prices[i] - valley);
	}
	//peak is the largest sell price that before i.so q[i]=max(if buy in here or the max before);
	for (int i = n - 2, peak = prices[n - 1]; i >= 0; i--){
		peak = max(peak, prices[i]);
		q[i] = max(q[i+1], peak - prices[i]);
	}
	int max_profit = 0;
	for (int i = 0; i < n; i++){
		max_profit = max(max_profit, p[i] + q[i]);
	}
	return max_profit;
}
