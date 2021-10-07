#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int solution(vector<int> numbers, int target) {
    int answer = 0;
    q.push({ 1, numbers[0] });
    q.push({ 1, -numbers[0] });

    while (!q.empty()) {
        int cnt = q.front().first;
        int sum = q.front().second;
        if (cnt == numbers.size() && sum == target) {
            answer++;
        }
        q.pop();
        if (cnt < numbers.size()) {
            q.push({ cnt + 1, sum + numbers[cnt] });
            q.push({ cnt + 1, sum - numbers[cnt] });
        }
    }

    return answer;

}
int main(void) {
    solution({ 1,1,1,1,1 }, 3);
}