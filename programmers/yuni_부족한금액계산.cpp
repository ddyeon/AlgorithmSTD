#include<iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    int index = 1;
    long long mon= money;
    while(count-- > 0){
        mon -= price * index;
        index++;
    }
    if(mon >= 0)answer = 0;
    else answer = -mon;
    return answer;
}

