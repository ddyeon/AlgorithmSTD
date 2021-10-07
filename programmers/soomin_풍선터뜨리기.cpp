#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	int dp[1000001];
	int smallest = a[0];
	for (int i = 1; i < a.size(); i++) {
		if (a[i] > smallest) {
			dp[i] = 1;
		}
		else if (a[i] < smallest) {
			smallest = a[i];
		}
	}
	smallest = a[a.size() - 1];
	for (int i = a.size() - 2; i >= 0; i--) {
		if (smallest < a[i]) {
			dp[i] += 1;
		}
		else if (a[i] < smallest) {
			smallest = a[i];
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (dp[i] < 2) {
			answer += 1;
		}
	}
	return answer;
}
int main()
{
	vector <int> v;
	v.push_back(-16);
	v.push_back(27);
	v.push_back(65);
	v.push_back(-2);
	v.push_back(58);
	v.push_back(-92);
	v.push_back(-71);
	v.push_back(-68);
	v.push_back(-61);
	v.push_back(-33);
	solution(v);
   
}


