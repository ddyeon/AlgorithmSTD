#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
void find(int m, vector <int> cookie) {
	vector<int> first;

	for (int i = 0; i <= m; i++) {
		int tot = 0;
		for (int j = i; j <= m; j++) {
			tot += cookie[j];
		}
		first.push_back(tot);
	}

	for (int i = cookie.size() - 1; i >= m + 1; i--) {
		int tot = 0;
		for (int j = m + 1; j <= i; j++) {
			tot += cookie[j];
		}
		for (int j = 0; j < first.size();j++) {
			if (first[j] == tot) {
				answer = max(answer, first[j]);
			}
		}
	}
}

int solution(vector<int> cookie) {
	for (int i = 0; i < cookie.size();i++) {
		find(i, cookie);
	}
	return answer;
}
int main() {
	vector <int> v;
	int ans;
	v.push_back(1);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(3);
	v.push_back(1);
	ans = solution(v);
	cout << ans;

	return 0;
}