//위클리 6주차 복서 정렬하기 -김수민
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare(vector<double> a, vector<double> b){
    if (a[0] == b[0]){
        if (a[1]==b[1]){
            if (a[2]==b[2]){
                return a[3] < b[3];
            }
            else{
                return a[2] > b[2];
            }
        }
        else{
            return a[1] > b[1];
        }
    }
    else{
        return a[0] > b[0];
    }
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<vector<double>> v;
    int N = weights.size();
    for (int i = 0 ; i < N; i++){
        int cnt = 0;
        int win = 0; int heavy = 0;
        double win_per = 1;
        for (int j = 0; j < N; j++){
            if (head2head[i][j]=='N'){
                cnt += 1;
            }
            else if (head2head[i][j] == 'W'){
                win += 1;
                if (weights[i] < weights[j]) heavy += 1;
            }
        }
        if (cnt == N) win_per = 0;
        else{
            win_per = double(win) / double(N-(cnt-1)-1);
        }
        vector <double> tmp;
        tmp.push_back(win_per); tmp.push_back(heavy);
        tmp.push_back(weights[i]); tmp.push_back(i + 1);
        v.push_back(tmp);
        
    }
    sort(v.begin(), v.end(), compare);
    for (int i=0; i<N; i++){
        answer.push_back(v[i][3]);
    }
    return answer;
}
