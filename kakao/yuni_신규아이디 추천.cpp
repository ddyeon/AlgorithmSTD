#include <string>
#include <vector>

using namespace std;
//3���� �̻� 15���� ���Ͽ��� �Ѵ�
// �ҹ���, ����, ����(-) ����(_) ��ħǥ(.) ���ڸ� 
//��ħǥ�� �ٵ� ó���� ���� ����� �� ������ �������� ����� �� ����. 



/*
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
     ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
*/
string solution(string new_id) {
    string answer = "";
    for (int i = 0; i < new_id.size(); i++) {
        if (i == 0 && new_id[i] == '.') { new_id.erase(i, 1); i--;continue; }
        if (new_id[i] >= 65 && new_id[i] <= 90) {
            new_id[i] += 32; continue;
        }
        if (new_id[i] >= 97 && new_id[i] <= 122)continue; //�ҹ��ڸ� pass
        else if (new_id[i] >= '0' && new_id[i] <= '9') continue; //���ڸ� pass
        else if (new_id[i] == '-' || new_id[i] == '_')continue; //���⳪ �����̸� pass
            else if (new_id[i] == '.') {
                 if (i !=0 && new_id[i - 1] == '.' && new_id[i] == '.') {
                    new_id.erase(i, 1);
                    i--;
                 }
            }

            else { //�ش� ���� �����
                new_id.erase(i, 1);
                i--;
            }
        }
    if (new_id.size() == 0) {
        new_id = "aaa";
        answer = "aaa";
    }
    if (new_id.size() > 15) new_id.erase(15);//���� �ڸ���

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