#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int game[102][102] = {{0},{0}, };
    for (int i = 0; i<results.size(); i++){
        game[results[i][0]][results[i][1]] = 1;
    }
    //플로이드 와샬
    for (int k = 1; k <= n; k++){ //4->3 3->1일때 4->1도 확실 ==> 저장
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if ((game[i][k] == 1)&&(game[k][j] == 1)){
                    game[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        int cnt = 0;
        for (int j = 1; j <= n; j++){
            if (game[i][j] == 1){
                cnt += 1;
            }
            if (game[j][i] == 1){
                cnt += 1;
            }
        }
        if (cnt == n-1){
            answer += 1;
        }
    }
    return answer;
}
