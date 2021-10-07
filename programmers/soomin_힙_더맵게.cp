#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a,b;
    priority_queue<int,vector<int>,greater<int>> sco;
    for (int i=0; i<scoville.size();i++){
        sco.push(scoville[i]);
    }
    
    while ((sco.top()<K)&&(sco.size()>1)){
        
        a=sco.top();
        sco.pop();
        b=sco.top();
        sco.pop();
        sco.push(a+(2*b));
        answer++;
        
    }
    if (sco.top()<K){
        return -1;
    }
    
    return answer;
}
