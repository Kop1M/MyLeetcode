//Two solution.
//The first is O(n2) complexity. For i, we store the longest number that use i as it's tail in dp[i]
//So, if nums[i]>nums[j](j is loop val from 0 to i-1),dp[i] = max(dp[i], dp[j] + 1);
//The second one :Let's think , we only need the length of LIS.So we create a array,
//it's size is the longest of LIS before i.Although this array is not LIS,we don't care.
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		vector<int> dp(nums.size(), 1);
		int Max = 1;
		for (int i = 1; i < nums.size(); i++){
			for (int j = 0; j < i; j++){
				if (nums[i]>nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			Max = max(Max, dp[i]);
		}
		return Max; 
	}

	//if(it==res.end())说明nums[i]比res中的元素都大那么可以加进来，同时也表示了LIS长度加1.
	//否则说明nums[i]比res中的某个元素小，由lower_bound就找到了比nums[i]大的那个最小的元素，
	//在他之前的元素也比nums[i]小，所以可以接上，但目前最长的LIS依旧是res.size()。只是那个局部
	//可以理解为一个小的LIS。只有当加入一个比res中元素都大的元素时，LIS才会真正增大。
	//比如res中为1,3,5。nums[i]=2,这样2替换了3。我们并不care是1,2,5还是1,3,5.只要知道最长是3就可以了。

int lengthOfLIS(vector<int>& nums)
{
	vector<int> res;
	for (int i = 0; i < nums.size(); i++){
		auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
		if (it == res.end())
			res.push_back(nums[i]);
		else
			*it = nums[i];
	}
	return res.size();
}