

//264. Ugly Number II 279. Perfect Squares
//Thinking is that all uglyNumber is create by former uglyNumber*2 or *3 or *5.So every time we find
//the smallest former uglyNumber*2 but must bigger than uglyNumber[i-1] as beTwo. Like this we find beThree,
//be Five. And uglyNumber[i] must be min(beTwo,beThree,beFive)


//279 is the same as 264.
int nthUglyNumber(int n)
{
	if (n == 0)
		return 0;
	int uglyNumber[100];
	uglyNumber[0] = 1;
	for (int i = 1; i < n; i++){
		int beTwo = 0, beThree = 0, beFive = 0;
		int open2 = 1, open3 = 1, open5 = 1;
		for (int j = 0; j < i; j++){
			if (!open2&&!open3&&!open5)
				break;
			if (open2 == 1){
				if (uglyNumber[j] * 2>uglyNumber[i - 1]){
					beTwo = uglyNumber[j] * 2;
					open2 = 0;
				}
			}
			if (open3 == 1){
				if (uglyNumber[j] * 3>uglyNumber[i - 1]){
					beThree = uglyNumber[j] * 3;
					open3 = 0;
				}
			}
			if (open5 == 1){
				if (uglyNumber[j] * 5 > uglyNumber[i - 1]){
					beFive = uglyNumber[j] * 5;
					open5 = 0;
				}
			}
		}
		uglyNumber[i] = min(beTwo, beThree);
		uglyNumber[i] = min(uglyNumber[i], beFive);
	}
	return uglyNumber[n - 1];
}


int numSquares(int n)
{
	int dp[100];
	dp[0] = 0;
	int begin = (int)sqrt(n);
	for (int i = 1; i <= n; i++){
		int Min = i;
		for (int j = (int)sqrt(i)*(int)sqrt(i); j >= 1; j = ((int)sqrt(j) - 1)*((int)sqrt(j) - 1)){
			Min = min(dp[i - j], Min);
		}
		dp[i] = Min + 1;
	}
	return dp[n];
}