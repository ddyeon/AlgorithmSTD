#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>basket;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int k = board[0].size();
	for (int i = 0; i < moves.size(); i++) {
		int tmp = moves[i] - 1;
		int put=0;
		for (int j = 0; j < k; j++) {
			if (board[j][tmp] != 0) {
				put = board[j][tmp];
				board[j][tmp] = 0;
				break;
			}
		}
		if (put == 0)
			continue;
		else {
			if (basket.empty())
				basket.push_back(put);
			else {
				if (basket.back() == put) {
					basket.pop_back();
					answer += 2;
				}
				else
					basket.push_back(put);
			}
		}
	}

	return answer;
}
