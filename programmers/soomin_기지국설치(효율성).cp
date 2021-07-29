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
int get_min_station(int no_station, int w){
    if (no_station > 0){
        int station = no_station / (2 * w + 1);
        int station_more = no_station % (2 * w + 1);
        if (station_more){
            return station + 1;
        }
        else{
            return station;
        }
    }
    return 0;
}
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int no_station;
    
    //처음부분
    no_station = stations[0] - (w+1);
    answer += get_min_station(no_station, w);
    
    //중간부분
    for (int i = 1; i< stations.size(); i++){
        int start = stations[i - 1] + w + 1;
        int end = stations[i] - (w + 1);
        no_station = end - start + 1;
        answer += get_min_station(no_station, w);
    }
    
    //끝부분
    no_station = n - (stations[stations.size() - 1] + w + 1) + 1;
    answer += get_min_station(no_station, w);
    
    return answer;
}
