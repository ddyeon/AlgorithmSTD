#include <string>
#include <vector>

using namespace std;
int arr[1010][1010];
bool visit[1010][1010];
vector<int> solution(int n) {
    vector<int> answer;
    int index = 0;
    int until = 0;
    for (int i = n; i > 0; i--) {
        until += i;
    }
    int cnt = 0;
    int first = 0, second = n - 1, third = n - 1;
    while (cnt <= until) {
        for (int i = first; i < n - first; i++) {
            if (cnt == until)break;
            if (visit[i][first] == 1)continue;
            arr[i][first] = ++cnt;
            visit[i][first] = 1;
        }
        if (cnt == until)break;
        for (int j = first + 1; j < n - first; j++) {
            if (cnt == until)break;
            if (visit[second][j] == 1)continue;
            arr[second][j] = ++cnt;
            visit[second][j] = 1;
        }
        if (cnt == until)break;

        for (int k = third; k > first; k--) {
            if (cnt == until)break;
            if (visit[k][k] == 1)continue;
            arr[k][k] = ++cnt;
            visit[k][k] = 1;
        }
        first++; second--; third--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(arr[i][j]);
        }
    }

    return answer;
}