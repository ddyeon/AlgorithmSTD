#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<char, int> uno;
int check;
int solution(string s) {
    int answer = 0;
    bool flag = true;
    for(int i=0; i<s.size(); i++){
        flag = true;
        uno['(']=0;
        uno['{']=0;
        uno['[']=0;
        uno[')']=0;
        uno['}']=0;
        uno[']']=0;
        check=0;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='('){
                uno[s[j]]++;
                check++;
            }   
            else if(s[j]=='{'){
                uno[s[j]]++;   
                check++;
            }
            else if(s[j]=='['){
                uno[s[j]]++;                        
                check++;
            }
            else if(s[j]==')'){
                if(uno['(']<=uno[s[j]]) flag = false;
                else uno[s[j]]++;
                if(check==2 && s[j-1]!='(')flag = false;
                check = 0;
            }
            else if(s[j]=='}'){
                if(uno['{']<=uno[s[j]]) flag = false;
                else uno[s[j]]++;
                if(check==2 && s[j-1]!='{')flag = false;
                check = 0;
            }
            else if(s[j]==']'){
                if(uno['[']<=uno[s[j]]) flag = false;
                else uno[s[j]]++;
                if(check==2 && s[j-1]!='[')flag = false;
                check = 0;
            }
            if(!flag){
                break;
            }
            
        }
        if(flag && uno['(']==uno[')'] && uno['{']==uno['}'] && uno['[']== uno[']']) {
                answer++;
//              cout<<s<<endl;
        }
        char a = s[0];
        s.erase(0,1);
        s += a;
    } 
    return answer;
}
