#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> sosu;
void soinsu(int num){
    for(int i=3;i<=num/3; i++){
        if(num % i==0)sosu.push_back(i);
    }
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    soinsu(size);
    for(int i=0; i<sosu.size(); i++)cout<<sosu[i]<<" ";
    cout<<endl;
    if(sosu.size()==1) {
        answer.push_back(sosu[0]);
        answer.push_back(sosu[0]);
    }
    else if(sosu.size()==2) {
        answer.push_back(sosu[1]);
        answer.push_back(sosu[0]);
    }
    else{
        int count = 0;
        int y = 0, x = 0;
        for(int i=0; i<= sosu.size() / 2; i++){
             y = sosu[sosu.size() - i - 1];
             x = sosu[i];
            count=0;
            int index = 0;
            while(count < brown){
                
                if(x < 0)break;
                count = y + (x-1) + (y-1) + (x-2); 
               
                y -= index * 2;
                x -= index * 2;
                index++;
            }
            if(count==brown){
                answer.push_back(sosu[sosu.size() - i- 1]);
                answer.push_back(sosu[i]);
                break;
            }
        }
    }
    
    return answer;
    
}
