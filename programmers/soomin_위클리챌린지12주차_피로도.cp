//위클리챌린지 12주차 - 김수민
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int dun_size = dungeons.size();
    vector <int> sunseo;
    for (int i = 0; i < dun_size; i++){
        sunseo.push_back(i);
    }
    do {
        int power = k; int tmp = 0;
        for(int i = 0; i < dun_size; i++){
            int idx = sunseo[i];
            if (power >= dungeons[idx][0]){
                power -= dungeons[idx][1];
                tmp += 1;
            }
        }
        answer = max(answer, tmp);
    }while (next_permutation(sunseo.begin(), sunseo.end()));
    
    return answer;
}
