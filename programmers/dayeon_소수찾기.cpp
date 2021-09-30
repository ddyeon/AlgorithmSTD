#include <string>
#include <vector>
#include <set>
using namespace std;
string tmp = "";
int visit[10000000];
int check[7];
bool isPrime(int num)
{
    int last = num / 2;
    if(num <=1)
        return false;
    for(int i = 2; i <= last; i++)
    {
         if ((num%i) == 0) 
        {
            return false;
        }
    }
    return true; 
    
}

void makeNum(string s, int cur)
{
    if(cur == tmp.length()+1)
        return;
    if(s !="")
    {
        int n = stoi(s);
        visit[n] = true;     
    }
    
    for(int i = 0; i < tmp.length(); i++)
    {
        if(!check[i])
        {
            check[i] = true;
            string next = s+tmp;
            makeNum(to_string(next[i]), cur+1);
            check[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    tmp = numbers;
    makeNum("",0);
    
    for(int i = 2; i < 1000000; i++)
    {
        if(visit[i] && isPrime(visit[i]))
            answer++;
    }
   
   
    
    return answer;
}