#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
/*

복서 선수들의 몸무게 weights, 복서 선수들의 전적 head2head 

*/
struct Node {
    int index;
    double win;
    int heav, weight;
};
bool oper(Node n1, Node n2){
    if(n1.win > n2.win)return true;
    else if(n1.win==n2.win){
        if(n1.heav > n2.heav)return true;
        else if(n1.heav == n2.heav){
            if(n1.weight > n2.weight)return true;
            else if(n1.weight == n2.weight){
                return n1.index < n2.index;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
unordered_map<int,double> score;
int heavy[1001];
vector<Node> ratio;
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    int match = 0;
    
    for(int i=0; i<head2head.size(); i++){
        score[i] = 0;
        match = 0;
        for(int j=0; j<head2head[i].size(); j++){
           if(head2head[i][j]=='W') {
                score[i]++;
                if(weights[j] > weights[i]) heavy[i]++;
                 match++;
            }
            else if(head2head[i][j]=='L') match++;
        }
        if(match!=0) score[i] = score[i] / match;
    }
    
    for(auto a = score.begin(); a!=score.end(); ++a) {
        ratio.push_back({a->first, a->second, heavy[a->first], weights[a->first]});
    }
    sort(ratio.begin(), ratio.end(), oper);
    for(int i=0; i<ratio.size(); i++) {
        answer.push_back(ratio[i].index + 1);
    }
    return answer;
}
