using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    //3(1+2+..+n)
    long long n = count;
    long long total = price*n*(n+1)/2;
    
    if(total > money)
        answer = total - money;
    

    return answer;
}