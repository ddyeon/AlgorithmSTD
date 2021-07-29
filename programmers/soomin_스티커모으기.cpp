#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int answer = 0;
int dfs(int cnt, int temp, vector<int> sticker, int start) {

	if (start == 0) {
		if ((cnt >= sticker.size() - 3)) {
			answer = max(temp, answer);
			return 0;
		}
	}
	if (start == 1) {
		if (cnt >= sticker.size() - 2) {
			answer = max(temp, answer);
			return 0;
		}
	}

	if (((start == 0) && (cnt + 2 <= sticker.size() - 2)) or ((start == 1) && (cnt + 2 <= sticker.size() - 1))) {
		dfs(cnt + 2, temp + sticker[cnt + 2], sticker, start);
	}
	if (((start == 0) && (cnt + 3 <= sticker.size() - 2)) or ((start == 1) && (cnt + 3 <= sticker.size() - 1))) {
		dfs(cnt + 3, temp + sticker[cnt + 3], sticker, start);
	}
}
int solution(vector<int> sticker)
{
	sticker.push_back(0);
	sticker.push_back(0);
	sticker.push_back(0);
	sticker.push_back(0);
	sticker.push_back(0);
	dfs(0, sticker[0], sticker, 0);
	dfs(1, sticker[1], sticker, 1);

	return answer;
}