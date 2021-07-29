//
//  main.cpp
//  soomin_기지국설치
//
//  Created by 김수민 on 2021/07/28.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    long long m[20000002];
    for (int i = 0; i < stations.size(); i++){
        int tempw = w;
        while (tempw > 0){
            m[stations[i]] = 1;
            m[stations[i]-tempw] = 1;
            m[stations[i]+tempw] = 1;
            tempw-=1;
        }
    }
    for (int i = 1; i <= n; i++){
        if (m[i] != 1){
            for (int j = 0; j < 2*w+1 ; j++ ){
                m[i + j] = 1;
                
            }
            answer += 1;
        }
    }
    
    cout << answer << endl;

    return answer;
}
