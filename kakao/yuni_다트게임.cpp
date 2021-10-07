#include <string>

using namespace std;
/*
* 3번의 기회, 0-10점
* S(1제곱),D,T //2,3제곱 -- 보너스
* 스타상 당첨 시 해당 점수와 전에 얻은 점수 2배, 아차상 당첨시 마이너스 -- 옵션
* 첫번쨰에 스타 당첨시 해당 점수만 2배
* 보너스는 점수마다 하나씩 옵션은 있을 수도 있고 없을 수도 있음ㄷ
*/
int arr[3];
int solution(string dartResult) {
    int answer = 0;
    string num = "";
    int index = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            num += dartResult[i];
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
            if (dartResult[i] == 'S')arr[index] = stoi(num);
            else if (dartResult[i] == 'D') arr[index] = stoi(num) * stoi(num);
            else if(dartResult[i]=='T')arr[index] = stoi(num)* stoi(num)* stoi(num);
            num = "";
            index++;
        }
        else if (dartResult[i] == '*') {
            if (index == 1) {
                arr[index - 1] *= 2;
            }
            else {
                arr[index - 1] *= 2;
                arr[index - 2] *= 2;
            }
        }
        else if (dartResult[i] == '#') {
            arr[index - 1] *= -1;
        }
    }
    for (int i = 0; i < 3; i++) answer += arr[i];
    return answer;
}
int main(void) {
 //   solution("1S2D*3T");
    solution("1D2S#10S");
    solution("1D2S0T");
    solution("1S*2T*3S");
    solution("1D#2S*3S");
}