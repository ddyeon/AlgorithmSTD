#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> uno;
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    for(int i=0; i<languages.size(); i++)uno[languages[i]] = preference[i];
    string job ="";
    int maxNum =0;
    for(int i=0; i<5; i++){
        int index=0;
        job="";
        for(index=0; table[i][index]!=' '; index++){
            job+=table[i][index];
        }
        int num =0;
        int grade = 6;
        while(grade-- > 1){
            int endIndex = table[i].find(' ', index + 1);
            string lan = table[i].substr(index+1, endIndex - index-1);
            num += uno[lan] * grade;
            index = endIndex;
        }
        if(maxNum < num){
            maxNum = num;
            answer = job;
        }
        else if(maxNum == num){
            if(job < answer)answer = job;
        }
    }
    return answer;
}
