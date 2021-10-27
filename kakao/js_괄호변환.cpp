#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string p) {
	stack <char> s;
	for (int i = 0; i < p.size(); i++) {
		if(s.empty())
			s.push(p[i]);
		else {
			if (s.top() == '(' && p[i] == ')')
			{
				s.pop();
				continue;
			}
			else
				s.push(p[i]);
		}
	}

	if (!s.empty())
		return false;
	else
		return true;
}

string solution(string p) {
	string answer = "";
	if (check(p))
		answer+=p;
	else {
		string u, v;
		int num1 = 0, num2 = 0;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == '(')
				num1++;
			else
				num2++;
			u += p[i];

			if (num1 != 0 && num1 == num2)
				break;
		}
		v = p.substr(u.size(), p.size() - u.size()); // u와 v로 나누기
		//////////////////////////////////////////////////////////////////
		if (check(u)) {
			answer += u;
			answer+=solution(v);
		}
		
		else {
			answer += '(';
			if (check(v))
				answer += v;
			else
				answer += solution(v);
			answer += ')';
			for (int i = 1; i < u.size() - 1; i++)
			{
				if (u[i] == '(')
					answer += ')';
				else
					answer += '(';
			}
			
		}
	}
	return answer;
}

int main() {
	string p = "(()())()";
	cout<<solution(p);
}