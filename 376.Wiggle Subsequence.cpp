// we consider this part : 5,2,3,6,5 we just remove 2 is OK,not 6,5.And then we will find that 
//if difference between 3 adjacent numbers is all + or -,it must remove one ,no matter which.
//In fact, remove which is decided by the back number.

int wiggleMaxLength(vector<int>& nums) {
	if (nums.size() == 0)
		return 0;
	for (auto tmp = nums.begin() + 1; tmp != nums.end();){
		if (nums.size() < 2)
			break;
		if (*tmp == *(tmp - 1))
			tmp = nums.erase(tmp);
		else
			tmp++;
	}
	if (nums.size() == 1)
		return 1;
	int sub = nums[1] - nums[0];
	int n = 0;
	for (int i = 2; i < nums.size(); i++){
		if (sub * (nums[i] - nums[i - 1])>0)
			n++;
		sub = nums[i] - nums[i - 1];
	}
	return nums.size() - n;
}