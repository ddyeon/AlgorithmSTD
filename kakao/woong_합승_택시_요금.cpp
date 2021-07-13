#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int map[200][200] {};

//플로이드-와샬 알고리즘??
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    int answer = 0;
    vector<int> candidate;

    s--; a--; b--; //0-base로 맞춰주기

    //Initialize map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            map[i][j] = 1000000;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        map[fares[i][0] - 1][fares[i][1] - 1] = fares[i][2];
        map[fares[i][1] - 1][fares[i][0] - 1] = fares[i][2];
    }  

    //플로이드-와샬
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][k] + map[k][j] < map[i][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        candidate.push_back(map[s][i] + map[i][a] + map[i][b]);
    }

    answer = *min_element(candidate.begin(), candidate.end());

    return answer;
}

int main(void)
{
    int n = 6;
    int s = 4;
    int a = 6;
    int b = 2;
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};

    cout << solution(n, s, a, b, fares) << endl;

    return 0;
}