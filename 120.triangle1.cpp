
// Firstly I find a complex way.
// dfs this triangle and store each result to a vector,then find the min one. use O(n) space 

int num = 0;
vector<int> v;
void dfs(int i, int j, vector<vector<int>>& vec)
{
	if (i>=vec.size())
		return;
	num += vec[i][j];
	if (i + 1 >= vec.size()){
		v.push_back(num);
		return;
	}
	dfs(i+1,j,vec);
	num -= vec[i + 1][j];
	dfs(i+1,j+1,vec);
	num -= vec[i + 1][j+1];
}

int minimumTotal(vector<vector<int>>& triangle) 
{
	dfs(0,0,triangle);
	int min = v[0];
	for (int i = 0; i < v.size(); i++){
		if (min>v[i])
			min = v[i];
	}
	return min;
}

//A better solution is just use triangle itself to store each min path.use recursion too
int minimumTotal(vector<vector<int>>& triangle)
{
	if (triangle.size() == 0)
		return 0;
	if (triangle.size() == 1)
		return triangle[0][0];
	int level = triangle.size();
	for (int i = level - 2; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}

