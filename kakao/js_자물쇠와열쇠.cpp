#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>>tmp(key.size(), vector<int>(key.size()));
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            tmp[j][key.size() - i - 1] = key[i][j];
        }
    }
    return tmp;
}

bool check(vector<vector<int>>whole,int N, int M) {
    for (int i = M - 1; i < M - 1 + N; i++) {
        for (int j = M - 1; j < M - 1 + N; j++) {
            if (whole[i][j] == 2 || whole[i][j] == 0)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int N = lock.size(), M = key.size();
    vector<vector<int>>whole(N + 2 * M - 2, vector<int>(N + 2 * M - 2));
    vector<vector<int>>tmp(N + 2 * M - 2, vector<int>(N + 2 * M - 2));
    for (int i = M - 1; i < M - 1 + N; i++) {
        for (int j = M - 1; j < M - 1 + N; j++) {
            whole[i][j] = lock[i + 1 - M][j + 1 - M];
            tmp[i][j] = lock[i + 1 - M][j + 1 - M];
            cout << whole[i][j] << "  ";
        }
        
    }
    
    if (check(whole, N, M))
        return true;

    for (int R = 0; R< 4; R++) {
        key=rotate(key);
        for (int i = 0; i < whole.size() - M + 1; i++) {
            for (int j = 0; j < whole.size() - M + 1; j++) {

                for (int k = 0; k < M; k++) {
                    for (int l = 0; l < M; l++) {
                        whole[k + i][l + j] += key[k][l];
                    }
                }

                if (check(whole, N, M))
                    return true;

                else {
                    whole = tmp;
                }

            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>>key = { {0, 0, 0}, { 1, 0, 0}, { 0, 1, 1 } };
    vector<vector<int>>lock = { {1, 1, 1,1}, {1,1,1,1},{ 1, 1, 0,1}, { 1, 0, 1,1 } };
    cout << solution(key, lock);
}