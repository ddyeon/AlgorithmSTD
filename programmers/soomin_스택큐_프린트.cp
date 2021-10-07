#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque <pair<int,int>> v;
    vector <int> print;
    bool flag=false;
    for (int i=0; i<priorities.size();i++){
        v.push_back(make_pair(priorities[i],i));
    }
    while (!v.empty()){
        flag=false;
        int impt = v[0].first;
        int imptidx = v[0].second;
        for (int i=1; i<v.size();i++){
            if (v[i].first>impt){
                v.push_back(make_pair(impt,imptidx));
                v.pop_front();
                flag=true;
                break;
            }
        }
        //print
        if (flag==false){
            print.push_back(imptidx);
            v.pop_front();
        }
        
    }
    for (int i=0; i<print.size();i++){
        if (print[i]==location){
            answer=i+1;
        }
    }
    return answer;
}
