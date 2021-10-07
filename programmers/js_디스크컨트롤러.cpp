#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    int time = 0;  
    int idx = 0;   
    sort(jobs.begin(), jobs.end()); 

    while (idx < jobs.size() || !pq.empty()) {

        if (idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push(jobs[idx++]);
            continue;
        }

        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }

        else {

            time = jobs[idx][0];
        }
    }

    return answer / jobs.size(); 
}
