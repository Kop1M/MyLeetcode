//dp[i] means the fewest number to form amount.
//so dp[i]=min of all dp[i-coins[j]]+1 (0<=j<coins.size())
//remember to consider if dp[i] is -1

int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	if (amount > 0 && coins.size() == 0)
		return -1;
	vector<int>dp(amount + 1, 0);
	for (int i = 1; i <= amount; i++){
		int tmpMin = INT_MAX;
		for (int j = 0; j < coins.size(); j++){
			if (i - coins[j] < 0 || dp[i - coins[j]] == -1)
				continue;
			tmpMin = min(tmpMin, dp[i - coins[j]] + 1);
		}
		dp[i] = tmpMin == INT_MAX ? -1 : tmpMin;
	}
	return dp[amount];
}