#include <string>
#include <vector>

using namespace std;

bool check(string s)
{
    int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			sum++;
		else if (s[i] == ')')
			sum--;
		if (sum < 0)
			return false;
	}
	return true;
}

string dfs(string p)
{
    if(p == "")
        return "";
    
    string u;
    string v;
    int i = 0;
	int left = 0; int right = 0;
	for (i = 0; i < p.length(); i++) {
		if (p[i] == '(')
			left++;
		else if (p[i] == ')')
			right++;
		if (left == right) { //올바른거 찾아서 나누기
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
    if(check(u))
        return u +dfs(v);
    else
    {
        string tmp = "(" + dfs(v) + ")";
        u = u.substr(1, u.length()-2);
        for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(')
				tmp = tmp + ')';
			else
				tmp = tmp + '(';
		}
		return tmp;
    }
    
}

string solution(string p) {
    string answer = "";
    
    answer = dfs(p);

    
    return answer;
}