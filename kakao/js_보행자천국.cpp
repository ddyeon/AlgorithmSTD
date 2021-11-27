#include <vector>
using namespace std;
int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int arr[501][501][2] = { 0 };
    arr[0][0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (city_map[i][j] == 1)
                continue;
            else if (city_map[i][j] == 0) {
                if (j + 1 < n)
                    arr[i][j + 1][0] = (arr[i][j + 1][0] + arr[i][j][0] + arr[i][j][1]) % MOD;

                if (i + 1 < m)
                    arr[i + 1][j][1] = (arr[i + 1][j][1] + arr[i][j][0] + arr[i][j][1]) % MOD;

            }
            else if (city_map[i][j] == 2) {
                if (j + 1 < n)
                    arr[i][j + 1][0] = (arr[i][j + 1][0] + arr[i][j][0]) % MOD;

                if (i + 1 < m)
                    arr[i + 1][j][1] = (arr[i + 1][j][1] + arr[i][j][1]) % MOD;
            }
        }
    }
    answer = (arr[m - 1][n - 1][0] + arr[m - 1][n - 1][1]) % MOD;
    return answer;
}
