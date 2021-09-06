#include <string>
#include <vector>
#include <string.h>
#include<algorithm>
#include <unordered_map>
#include<queue>
using namespace std;
/*
�������� ���� ����
�ĺ�Ű ���� - ���ϼ�, �ּҼ�
1���� �÷����� / �������� ������ ��� 
*/
unordered_map<string, int> map;
unordered_map<int, int> visit;
unordered_map<int, int> notunique;
unordered_map<int, int> uniqued;

queue<string> q;
bool flag = true;
int visited[10000];
string tmp;
void checked(string s, string check) {
    string t = check;

    if (t != "") {
        sort(t.begin(), t.end());
        if (uniqued[stoi(t)] == 1) {
            flag = false;
            return;
        }

    }
    for (int i = 0; i < s.size(); i++) {
        if (visited[i] == 1)continue;
        visited[i] = 1;
        checked(s, check + s[i]);
        if (!flag)return;
        visited[i] = 0;

    }
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    int col = relation[0].size();
    int row = relation.size();
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            string tmp = relation[j][i] + to_string(i + 1);
            if (map[tmp] == 1) {
                flag = false;
                break;
            }
            else map[tmp] = 1;
        }
        if (!flag) {
            q.push(to_string(i + 1));  //ó���� nonunique�� �ֵ鸸 �������
            notunique[i+1] = 1;
        }
        else {
            answer++;
            uniqued[i + 1] = 1;
        }
        flag = true;
    }
    while (!q.empty()) {

        int index = stoi(q.front());
        string ii = q.front();
        q.pop();
        
        for (int i = 0; i < col; i++) {
            flag = true;
            if (uniqued[i + 1] == 1) continue;
            if (ii.size() == 1 && notunique[i+1] == 0)continue; //nonunique1 + nonunique1�� �ȵ�
            if (notunique[i+1] == 1 && uniqued[index] == 1)continue; //����Ű + �ĺ�Ű�� ����
            int check = ii.find(to_string(i+1));
            if (check != -1 ) continue; //�̹� ������ �ִ� �������� Ȯ��
            string in = to_string(i+1) + to_string(index);
            sort(in.begin(), in.end()); 
            
            if (visit[stoi(in)]) continue; //�̹� Ȯ���ѰŸ� pass
            visit[stoi(in)] = 1;
            if (in.size() > 2) {
                memset(visited, 0, 10000); //Ȥ�� �� �߿� �ĺ�Ű�� �Ǵ� �� ������ �ٷ� pass
                checked(in, "");
                if (!flag)continue;
            }
            for (int j = 0; j < row; j++) {
                string tmp = "";
                for (int ll = 0; ll < in.size(); ll++) {
                    tmp += relation[j][(in[ll]-'0') - 1] + in[ll];
                }
                if (map[tmp] == 1) {
                    flag = false;
                    break;
                }
                else map[tmp] = 1;
            }
            if (!flag) {
                notunique[stoi(in)] = 1;
                q.push(in);

            }
            else {
                answer++; 
                uniqued[stoi(in)] = 1;
            }
        }
    }
    return answer;
}
