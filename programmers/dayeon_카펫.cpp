#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> v;

// void calDivisor(int yellow)
// {
//     for(int i = 1; i*i < yellow; i++)
//     {
//         if(yellow % i == 0)
//             v.push_back({yellow/i , i}); // 가로길이, 세로길이
    
//     }
    
//     sort(v.begin(), v.end());
//     reverse(v.begin(), v.end());
// }

// vector<int> solution(int brown, int yellow) {
//     vector<int> answer;
    
//     if(yellow == 1)
//         v.push_back({1,1});
//     else
//         calDivisor(yellow);
    
//     for(int i = 0; i < v.size(); i++)
//     {
//         int x = v[i].first + 2;
//         int y = v[i].second + 2;
        
//         if((x*y)-yellow == brown)
//         {
//             answer.push_back(x);
//             answer.push_back(y);
//             break;
//         }
//     }
    
 
//     return answer;
// }

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int i = yellow ; i >= (yellow/i) ; i--){
        if (yellow%i != 0) {
            continue;
        }
        if (((2*i)+(2*(yellow/i))+4) == brown) {
            answer.push_back(i+2);
            answer.push_back((yellow/i)+2);
            break;
        }
        
    }
    
    return answer;
}