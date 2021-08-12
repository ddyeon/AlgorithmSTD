#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    
    sort(citations.begin(), citations.end());
    //01365
    
    for(int i = 0; i < citations.size(); i++)
    {
         int hindex = size-i;
        
        if (citations[i] >= hindex) {
            answer = hindex;
            break;
        }
    }
    
    
    return answer;
}