
//Firstly we init dp[0][0]-dp[0][n-1] and dp[0][0]-dp[m-1][0],create a dp[100][100],dp[i][j] means
//the largest sqrt(square) can be with this block as it's lowest right corner;
int maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();
	int dp[100][100];
	for (int i = 0; i < n; i++){
		if (matrix[0][i] == '1')
			dp[0][i] = 1;
		else
			dp[0][i] = 0;
	}
	for (int j = 0; j < m; j++){
		if (matrix[j][0] == '1')
			dp[j][0] = 1;
		else
			dp[j][0] = 0;
	}
	for (int j = 1; j < m; j++){
		for (int i = 1; i < n; i++){
			if (matrix[j][i] == '0')
				dp[j][i] = 0;
			else if (dp[j - 1][i] == 0 || dp[j][i - 1] == 0){
				dp[j][i] = 1;
			}
			else{
				if (dp[j - 1][i] + 1 == dp[j][i - 1] + 1){
					if (matrix[j - dp[j - 1][i]][i - dp[j - 1][i]] == '0')
						dp[j][i] = dp[j - 1][i];
					else
						dp[j][i] = dp[j - 1][i] + 1;
				}
				else
					dp[j][i] = min(dp[j - 1][i] + 1, dp[j][i - 1] + 1);
			}
		}
	}
	int Max = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			Max = max(dp[i][j], Max);
		}
	}
	return Max*Max;
}
