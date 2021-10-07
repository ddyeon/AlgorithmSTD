#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int dp[20001] = { 0, };
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < edge.size();i++) {
        vector <int> v = m[edge[i][0]];
        vector <int> v2 = m[edge[i][1]];
        v.push_back(edge[i][1]);
        v2.push_back(edge[i][0]);
        m[edge[i][0]] = v;
        m[edge[i][1]] = v2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m[i].size();j++) {
            int mini = 50001;
            if ((dp[m[i][j]] == 0)&&(m[i][j]!=1)) {
                for (int k = 0; k < m[m[i][j]].size(); k++) {
                    if (dp[m[m[i][j]][k]] < mini) {
                        mini = dp[m[m[i][j]][k]];
                    }
                }
                dp[m[i][j]] = mini + 1;
            }
        }
    }
    int max = *max_element(dp, dp+n+2);
    for (int i = 0; i < n + 1; i++) {
        if (dp[i] == max){
            answer += 1;
        }
    }

    return answer;
}
