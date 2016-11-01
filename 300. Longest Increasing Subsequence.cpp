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

	//if(it==res.end())˵��nums[i]��res�е�Ԫ�ض�����ô���Լӽ�����ͬʱҲ��ʾ��LIS���ȼ�1.
	//����˵��nums[i]��res�е�ĳ��Ԫ��С����lower_bound���ҵ��˱�nums[i]����Ǹ���С��Ԫ�أ�
	//����֮ǰ��Ԫ��Ҳ��nums[i]С�����Կ��Խ��ϣ���Ŀǰ���LIS������res.size()��ֻ���Ǹ��ֲ�
	//�������Ϊһ��С��LIS��ֻ�е�����һ����res��Ԫ�ض����Ԫ��ʱ��LIS�Ż���������
	//����res��Ϊ1,3,5��nums[i]=2,����2�滻��3�����ǲ���care��1,2,5����1,3,5.ֻҪ֪�����3�Ϳ����ˡ�

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