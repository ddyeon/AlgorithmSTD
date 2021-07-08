#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> buho;
    vector<char> location;
    string n = "";
    
    for(int i = 0; i < expression.size(); i++)
    {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            num.push_back(stoi(n));
            n = "";
            //부호 없으면 추가
            if(find(buho.begin(), buho.end(), expression[i]) == buho.end())
                buho.push_back(expression[i]);
            location.push_back(expression[i]);
        }
        else
            n += expression[i];
    }
    
    num.push_back(stoi(n));
    sort(buho.begin(), buho.end());
    
    do
    {
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = location;
        
        for(int i = 0; i < exp.size(); i++)
        {
            for(int j = 0; j < tmp_loc.size(); j++)
            {
                if(exp[i] == tmp_loc[j])
                {
                    if(tmp_loc[j] == '+'){
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    }
                    else if(tmp_loc[j] == '-'){
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    }
                    else if(tmp_loc[j] == '*'){
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];
                    }
                    
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }
        
        if(answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while(next_permutation(exp.begin(), exp.end()));
    
    return answer;
}
