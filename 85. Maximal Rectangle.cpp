//The Maximum Rectangle is the maxArea of histogram from one row.
//so we just need to dynamic programming to find the largest 1 series and caculate 
//every row's biggest histogram.

int largestRectangleArea(vector<int>& heights)
{
	stack<int> s;
	heights.push_back(0);
	int result = 0;
	for (int i = 0; i < heights.size();){
		if (s.empty() || heights[i]>heights[s.top()])
			s.push(i++);
		else{
			int tmp = s.top();
			s.pop();
			result = max(result, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
		}
	}
	return result;
}
int maximalRectangle(vector<vector<char>>& matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	vector<vector<int>> dp(row, vector<int>(col));
	for (int i = 0; i < col; i++)
		dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
	for (int j = 1; j < row; j++){
		for (int i = 0; i < col; i++){
			if (matrix[j][i] == '0')
				dp[j][i] = 0;
			else
				dp[j][i] = dp[j - 1][i] + 1;
		}
	}
	int maxArea = 0;
	for (int i = 0; i < row; i++)
		maxArea = max(maxArea, largestRectangleArea(dp[i]));
	return maxArea;
}