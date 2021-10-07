#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool graph[110][110] {}; //graph[win][lose] = true

//플로이드 와샬??
int solution(int n, vector<vector<int>> results) 
{
    int answer = 0;

    for (int i = 0; i < results.size(); i++) {
        graph[results[i][0]][results[i][1]] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) {
                cnt++;
            }
        }
        if (cnt == n - 1) {
            answer++;
        }
    }

    return answer;
}

int main(void)
{
    int n = 5;
    vector<vector<int>> results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

    cout << solution(n, results) << endl;

    return 0;
}