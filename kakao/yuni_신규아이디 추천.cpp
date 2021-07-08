#include <string>
#include <vector>

using namespace std;
//3글자 이상 15글자 이하여야 한다
// 소문자, 숫자, 뺴기(-) 밑줄(_) 마침표(.) 문자만 
//마침표는 근데 처음과 끝에 사용할 수 없으며 연속으로 사용할 수 없다. 



/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/
string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (i == 0 && new_id[i] == '.') { new_id.erase(i, 1); i--;continue; }
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            new_id[i] += 32; continue;
        }
        if (new_id[i] >= 97 && new_id[i] <= 122)continue; //소문자면 pass
        else if (new_id[i] >= '0' && new_id[i] <= '9') continue; //숫자면 pass
        else if (new_id[i] == '-' || new_id[i] == '_')continue; //빼기나 밑줄이면 pass
            else if (new_id[i] == '.') {
                 if (i !=0 && new_id[i - 1] == '.' && new_id[i] == '.') {
                    new_id.erase(i, 1);
                    i--;
                 }
            }

            else { //해당 문자 지우기
                new_id.erase(i, 1);
                i--;
            }
        }
    if (new_id.size() == 0) {
        new_id = "aaa";
        answer = "aaa";
    }
    if (new_id.size() > 15) new_id.erase(15);//길이 자르기

    while (1) {
        if (new_id[new_id.size() - 1] == '.')new_id.erase(new_id.size() - 1, 1);
        else break;
    }
    if (new_id.size() <= 2) {
        while (new_id.size() != 3)new_id += new_id[new_id.size() - 1];
   }
    return answer;
}

int main(void) {
//    solution("...!@BaT#*..y.abcdefghijklm");
//    solution("z-+.^.");
//    solution("=.=");
//    solution("123_.def");
    solution("abcdefghijklmn.p");
}