// 위클리 8주차 최소 직사각형 - 김수민
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] > b[1];
}
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    sort(sizes.begin(), sizes.end(), greater<>());
    int garo_max = sizes[0][0];
    
    sort(sizes.begin(),sizes.end(),compare);
    int sero_max = sizes[0][1];
    int sero = 0; int garo = garo_max;
    for (int i = 0; i < sizes.size(); i++){
        if ((sizes[i][1] <= garo) && (sizes[i][0] < sizes[i][1])){
            if (sizes[i][0] > sero){
                sero = sizes[i][0];
            }
            continue;
        }
        else{
            if (sizes[i][1] > sero){
                sero = sizes[i][1];
            }
            break;
        }
    }
    sort(sizes.begin(), sizes.end(), greater<>());
    cout <<sizes[0][0];
    int sero_tmp = sero_max; int garo_tmp = 0;
    for (int i = 0; i < sizes.size(); i++){
        if ((sizes[i][0] <= sero_tmp) &&(sizes[i][1] < sizes[i][0])){
            //뒤집기
            if (sizes[i][1] > garo_tmp){
                garo_tmp = sizes[i][1];
            }
            
            continue;
        }
        else{
            if (sizes[i][0] > garo_tmp){
                garo_tmp = sizes[i][0];
            }
            break;
        }
    }
    
    answer = min(garo * sero, garo_tmp*sero_tmp);

    return answer;
}
