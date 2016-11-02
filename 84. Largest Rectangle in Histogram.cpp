//http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html
// Learn how to write this code. not mine(The second code)
int largestRectangleArea2(vector<int>& heights)
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

//My version
int largestRectangleArea(vector<int>& heights)
{
	heights.push_back(0);
	int n = heights.size();
	int Max = 0;
	int index = 0;
	stack<int> sy;
	stack<int> sz;
	int open = 0;
	for (int i = 0; i < n; i++){
		while (1){
			if (sz.empty() || sz.top() <= heights[i]){
				if (open == 1)
					sy.push(index);
				else
					sy.push(i);
				sz.push(heights[i]);
				open = 0;
				break;
			}
			else{
				open = 1;
				index = sy.top();
				int peek = sz.top();
				sy.pop();
				sz.pop();
				Max = max(Max, peek * (i - index));
			}
		}
	}
	return Max;
}