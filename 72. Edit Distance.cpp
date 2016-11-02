/*
	The shortest edit distance.
	editDistance[i][j] means the shortest distance between word1[i-1] to word2[j-1]( subscript is from 1)
	so equation of state : 
	editDistance[i][0]=i;
	editDistance[0][j]=j;
	editDistance[i][j]=editDistance[i-1][j-1] (if word1[i-1]==word2[j-1])
	editDistance[i][j]=min(editDistance[i][j-1]+1, means insert word2[j-1] int the last
						   editDistance[i-1][j]+1, means delete word1[i-1]...
						   editDistance[i-1][j-1]+1, means change word1[i-1] to word2[j-1])
*/

int minDistance(string word1, string word2) {
	int editDistance[word1.size() + 1][word2.size() + 1];
	int length1 = word1.size();
	int length2 = word2.size();
	for (int i = 0; i <= length1; i++)
		editDistance[i][0] = i;
	for (int j = 0; j <= length2; j++)
		editDistance[0][j] = j;
	for (int i = 1; i <= length1; i++){
		for (int j = 1; j <= length2; j++){
			if (word1[i - 1] == word2[j - 1])
				editDistance[i][j] = editDistance[i - 1][j - 1];
			else{
				editDistance[i][j] = min(editDistance[i - 1][j], editDistance[i][j - 1]);
				editDistance[i][j] = min(editDistance[i - 1][j - 1], editDistance[i][j]) + 1;
			}
		}
	}
	return editDistance[length1][length2];
}