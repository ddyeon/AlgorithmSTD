// 위클리챌린지 _ 1주차 부족한 금액 계산하기
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long tmp = 0;
    for (int i = 0; i < count; i++){
        tmp += price * (i + 1);
    }
    if (money > tmp){
        answer = 0;
    }
    else{
        answer = tmp - money;
    }
    return answer;
}
