#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> numbers, int cnt, int t, int anw) {
	if (cnt == numbers.size() - 1) {
		if (t == anw) {
			answer += 1;
		}
		return;
	}

	dfs(numbers, cnt + 1, t, anw - numbers[cnt + 1]);
	dfs(numbers, cnt + 1, t, anw + numbers[cnt + 1]);

}
int solution(vector<int> numbers, int target) {
	dfs(numbers, 0, target, -numbers[0]);
	dfs(numbers, 0, target, numbers[0]);
	return answer;
}