#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque <int> pq;
    
    for (int i = 0; i < operations.size(); i++){
        if (operations[i][0] =='I'){
            int num = 0;
            if (operations[i][2]=='-'){
                num = -1 * (stoi(operations[i].substr(3, operations[i].size())));
            }
            else{
                num = stoi(operations[i].substr(2, operations[i].size()));
            }
            pq.push_back(num);
            sort(pq.begin(),pq.end());
        }
        else if (operations[i][0] == 'D'){
            if (pq.empty()){
                continue;
            }
            else{
                if (operations[i][2] == '1'){
                    pq.pop_back();
                }
                else{
                    pq.pop_front();
                }
            }
        }
        
    }
    if (pq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq[pq.size()-1]);
        answer.push_back(pq[0]);
    }
    return answer;
}
