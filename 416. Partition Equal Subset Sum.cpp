
//dp[j]��ʾ�Ƿ���Ԫ�صĺ�Ϊj;״̬ת�Ʒ��̣�dp[j]=dp[j]||dp[j-nums[i]]  (nums[i]<=j<=sum)
//dp��ʼ������dp[0]Ϊtrue��������Ϊfalse
//dp[j-nums[i]]�����Ƿ���Ԫ�صĺ�Ϊj-nums[i]������еĻ����ϵ�ǰԪ��nums[i]�Ϳ�����

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