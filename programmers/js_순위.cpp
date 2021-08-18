#include <string>
#include <vector>
#include <iostream>

int arr[101][101] = { 0 };
using namespace std;
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
   
    for (int i = 0; i < results.size(); i++) {
        arr[results[i][0]][results[i][1]] = 1;
    }

   

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 || arr[j][i] == 1) {
                cnt++;
            }
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}

