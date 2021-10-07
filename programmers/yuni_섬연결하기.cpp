#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int island[101][101];
bool visit[101];
bool check[101];
bool oper(vector<int> v1, vector<int> v2) {
    if (v1[2] < v2[2]) return true;
    else return false;
}
bool flag;
void cycle(int a, int b, int c, int n) {
    if (a == b) {
        flag = true;
        return;
    }
    for (int i = 0; i < n; i++) {        
        if (check[i] == 1)continue;
        if (island[a][i]) {
            check[i] = 1;
            cycle(i, b, c, n);
        }
        
        if (flag)return;
    }
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;
    sort(costs.begin(), costs.end(), oper);
    for (int i = 0; i < costs.size(); i++) {
        if (island[costs[i][0]][costs[i][1]]!=0 && island[costs[i][1]][costs[i][0]]!=0) continue;
        else {
            if (visit[costs[i][0]] && visit[costs[i][1]]) {
                flag = false;
                memset(check, 0, sizeof(check));
                check[costs[i][0]] = 1;
                cycle(costs[i][0], costs[i][1], costs[i][0], n);
                if (flag)continue;
            }
            island[costs[i][0]][costs[i][1]] = 1;
            island[costs[i][1]][costs[i][0]] = 1;
            visit[costs[i][0]] = 1;
            visit[costs[i][1]] = 1;
            answer += costs[i][2];
            cnt++;
        }
        if (cnt == n - 1)break;
    }

    return answer;
}
int main(void) {
//    solution(4, { {0,1,5},{1,2,3},{2,3,3},{1,3,2},{0,3,4} });
    solution(5, { {0,1,5},{1,2,3},{2,3,3},{3,1,2},{3,0,4},{2,4,6},{4,0,7} });
    solution(5, { {0,1,1},{3,4,1},{1,2,2},{2,3,4} });
    solution(4, { {0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8} });
}