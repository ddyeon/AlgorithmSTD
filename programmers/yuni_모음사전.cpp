#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
/*
a, aa, aaa, aaaa, aaaaa, aaaae, aaaai, aaaao, aaaau
aaea, 

*/

using namespace std;
unordered_map<string,int> uno;
unordered_map<string,int> visit;

char moeum[5] = {'A','E','I','O','U'};
int index = 0;
void dfs(string tmp){
    if(tmp.size()>5){
        index--;
        return;
    }  
  //  cout<<tmp<<" " << index<<endl;

    if(tmp!="" && uno[tmp]==0)uno[tmp] = index;
    for(int i=0; i<5; i++){
        index++;
        if(visit[tmp + moeum[i]] == 1) continue;
        visit[tmp + moeum[i]] = 1;
        dfs(tmp + moeum[i]);    
    }
}
int solution(string word) {
    int answer = 0;
    dfs("");
    answer = uno[word];
    return answer;
}
