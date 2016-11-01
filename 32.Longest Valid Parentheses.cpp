/*
	Build 3 stacks. Store ( and ('s location which not match and )'s location which not match
	then ergodic loc array.
*/

int longestValidParentheses(string s)
{
	stack<char> sign;
	stack<int> locl;//(不匹配的位置
	stack<int>locr;//)不匹配的位置
	int num = 0;
	int Max = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			sign.push(s[i]);
			locl.push(i);
		}
		else{
			if (sign.empty())
				locr.push(i);
			else{
				num += 2;
				sign.pop();
				locl.pop();
			}
		}
	}
	vector<int> loc;
	while (!locl.empty()){
		loc.push_back(locl.top());
		locl.pop();
	}
	while (!locr.empty()){
		loc.push_back(locr.top());
		locr.pop();
	}
	if (loc.empty() || (loc.size() == 1 && (loc[0] == 0 || loc[0] == s.size() - 1)))
		return Max = num;
	sort(loc.begin(), loc.end());
	Max = loc[0] - 0 - 1;
	for (int i = 1; i < loc.size(); i++){
		Max = max(Max, loc[i] - loc[i - 1] - 1);
	}
	Max = max(Max, (int)(s.size() - 1 - loc[loc.size() - 1]));
	return Max;
}