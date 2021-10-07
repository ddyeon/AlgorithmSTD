using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for (int i = 1; i <= count; i++) {
        answer += (long long)price * i;
    }
    if (answer > money)
        answer -= (long long)money;

    else
        answer = 0;

    return answer;
}