
//dp[j]表示是否有元素的和为j;状态转移方程：dp[j]=dp[j]||dp[j-nums[i]]  (nums[i]<=j<=sum)
//dp初始化除了dp[0]为true，其他都为false
//dp[j-nums[i]]就是是否有元素的和为j-nums[i]，如果有的话加上当前元素nums[i]就可以了

bool canPartition(vector<int>& nums)
{
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
		sum += nums[i];
	if (sum % 2 == 1)
		return false;
	sum /= 2;
	bool dp[100];
	dp[0] = true;
	for (int i = 0; i < nums.size(); i++){
		for (int j = sum; j>=nums[i]; j--){
			dp[j] = dp[j] || dp[j - nums[i]];
			if (dp[sum])
				return true;
		}
	}
	return false;
}