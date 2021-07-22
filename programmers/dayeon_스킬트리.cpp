#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for(int i = 0; i < skill_trees.size(); i++)
    {
        string current = skill_trees[i];
        vector<char> v;

        for(int j = 0; j < current.size(); j++)
        {
            //포함되어있으면
            if (skill.find(current[j]) != string::npos)
            {
               v.push_back(current[j]);
            }
            else
                continue;
            
            
        }

       bool check =true;
        for(int j = 0; j < v.size(); j++)
        {
            cout << v[j] << skill[j] << endl;
            if(v[j] != skill[j])
            {
                check = false;
                break;
            }    
        }
        if(check)
            answer++;

        
    }



    return answer;
}