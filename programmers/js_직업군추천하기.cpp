#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    int sum = 0;
    for (int i = 0; i < table.size(); i++) {
        vector<string>v;
        string str;
        int tmpsum=0;
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] != ' ')
                str += table[i][j];
            
            else {
                v.push_back(str);
                str = "";
            }

            if (j == table[i].size() - 1)
                v.push_back(str);
        }

        for (int j = 0; j < languages.size(); j++) {
            int idx = find(v.begin(), v.end(), languages[j]) - v.begin();
           
            if (idx == v.size())
                continue;
            else {
                tmpsum += (6 - idx) * preference[j];
            }
        }
       
        if (tmpsum > sum) {
            sum = tmpsum;
            answer = v[0];
        }
        else if (tmpsum == sum) {
            if (answer > v[0])
                answer = v[0];
        }
    }
    
    
    return answer;
}

int main() {
    vector<string> table = { "SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"
    };
    vector<string> languages = { "PYTHON", "C++", "SQL" };
    vector<int> p = { 7, 5, 5 };
    cout<<solution(table, languages, p);
    //cout<<find(p.begin(), p.end(), 5) - p.begin();

}