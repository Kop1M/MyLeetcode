/*
	Use a recursion DP function to find the cost that can guarantee to find the target which is in[valley,peek].
	Obviously,dp[valley,peek]=The min of all max(DP(valley, i - 1, dp), DP(i + 1, peek, dp)) + i)  (valley<=i<=peek);
*/
	int DP(int valley, int peek, vector<vector<int>>&dp)
	{
		if (valley >= peek)
			return 0;
		if (dp[valley][peek] != 0)
			return dp[valley][peek];
		int tmpMin = INT_MAX;
		for (int i = valley; i <= peek; i++)
			tmpMin = min(tmpMin, max(DP(valley, i - 1, dp), DP(i + 1, peek, dp)) + i);
		return dp[valley][peek] = tmpMin;
	}

	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return DP(1, n, dp);
	}
