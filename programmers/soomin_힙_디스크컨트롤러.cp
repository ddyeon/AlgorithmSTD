#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({jobs[0][1],0});
    int done[502] = {0, };
    int time = jobs[0][0];
    done[0] = 1;
    int anw = 0;
    while (!pq.empty()){
        time += pq.top().first;
        anw += time - jobs[pq.top().second][0];
        pq.pop();
        for (int i = 0; i < jobs.size(); i++){
            if ((jobs[i][0] <= time) &&(done[i]==0)){
                done[i] = 1;
                pq.push({jobs[i][1],i});
            }
        }
        if (pq.empty()){
            int temp = 0;
            for (int i = 0; i < jobs.size(); i++){
                if ((done[i]==0)&&(temp==0)){
                    temp = jobs[i][0];
                }
                if ((done[i]==0)&&(jobs[i][0]==temp)){
                    done[i] = 1;
                    pq.push({jobs[i][1],i});
                   
                }
            
             }
            time = jobs[pq.top().second][0];
        }
    }
    answer = anw / jobs.size();
    return answer;
}
