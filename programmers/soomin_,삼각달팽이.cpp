#include <string>
#include <vector>
#include <map>
using namespace std;
void snail(int start, int turn) {
	vector<vector<int>> v;
	int new_start = 0;
	for (int i = start; i <= start + (n - turn) - (2 * turn + 1); i++) {
		v[(i - 1) % n].insert(v[(i - 1) % n].begin() + turn, i);
	}
	for (int i = start + (n - turn) - (2 * turn + 1) + 1; i < 2 * (n + turn); i++) {
		v[n - turn].push_back(i);
	}
	int s = v[n - turn][turn] + v[n - turn][n - turn * 2 - 1];
	for (int i = 2 * (n + turn); i < 2 * (n + turn) + n - turn - 2(turn + 1); i++) {
		v[? ? ].insert(v.end() - turn, i);
		new_start = i;
	}
	return new_start;
}
vector<int> solution(int n) {
	vector<int> answer;
	map <int, vector<int>> m;
	int turn = 0;
	int new_start = snail(1, turn);
	while (new_start < n * (n + 1) / 2) {
		turn += 1;
		new_start = snail(new_start, turn);
	}


	return answer;
}