#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//보석의 종류 파악,
vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    vector<string> temp = gems;
    int germs_size = 0;
    map <string, int> m;
    set <string> s;
   

    // //보석의 종류 파악,
    // sort(temp.begin(), temp.end());
    // temp.erase(unique(temp.begin(), temp.end()));
    // for (int i = 0; i < temp.size(); i++)
    //     cout << temp[i] << endl;
    // germs_size = temp.size();

    for (int i = 0; i < gems.size(); i++)
        s.insert(gems[i]);

    vector <pair<int,int>> v;
    int start, end = 0;

    while(true)
    {
        if(m.size() == s.size())
        {
            v.push_back({start,end-1});

            if(m[gems[start]] == start)
                m.erase(gems[start]);
            start++;
            if(end > gems.size())
                break;
        }
        else
        {
            if(end>=s.size())
                break;
            m[gems[end]] = end;
            end++;
        }
        
    }

    sort(v.begin(), v.end());
    answer.push_back(v.front().first+1);
    answer.push_back(v.front().second+1);



    return answer;
}

