#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());
    
    do
    {
        int tired = k;
        int cnt = 0;
       for(int i = 0; i < dungeons.size(); i++)
       {
           if(tired >= dungeons[i][0])
           {
               tired -= dungeons[i][1];
               cnt++;
           } 
       }
        if(cnt > answer)
            answer = cnt;
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    
    return answer;
}