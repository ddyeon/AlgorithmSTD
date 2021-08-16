#include <string>
#include <vector>

using namespace std;
/*
n명의 권투 선수
1:1 방식 진행 
A선수가 B선수보다 실력이 좋다면 A 선수는 B선수를 항상 이김
플로이드 와샬을 이용해서 갱신해줘야 함
*/
int arr[110][110];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //이긴 거 진거를 어떻게 구별하지

    for (int i = 0; i < results.size(); i++) {
        arr[results[i][0]][results[i][1]] = 1; // 이긴거 
        arr[results[i][1]][results[i][0]] = -1; // 진거
    }
    
    for (int i = 1; i <= n; i++) { //시작 노드 
        for (int j = 1; j <= n; j++) { //중간 노드
            for (int k = 1; k <= n; k++) { //끝 노드
                if (arr[i][j] == 1 && arr[j][k] == 1) {// i가 j를 이기고 j가 k를 이기면 i가 k를 이긴거임
                    arr[i][k] = 1;
                    arr[k][i] = -1;
                }
                else if (arr[i][j] == -1 && arr[j][k] == -1) { //i가 j에게 지고 j가 k에게 졌으면 i가 k에게 진거임
                    arr[k][i] = 1;
                    arr[i][k] = -1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) { //나 빼고 나머지 애들이 다 확실하면 내 순위를 알 수 있음
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0) cnt++;
        }
        if (cnt == n - 1) answer++;
    }

    return answer;
}

int main(void) {
    solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}