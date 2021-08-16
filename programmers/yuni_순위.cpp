#include <string>
#include <vector>

using namespace std;
/*
n���� ���� ����
1:1 ��� ���� 
A������ B�������� �Ƿ��� ���ٸ� A ������ B������ �׻� �̱�
�÷��̵� �ͼ��� �̿��ؼ� ��������� ��
*/
int arr[110][110];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    //�̱� �� ���Ÿ� ��� ��������

    for (int i = 0; i < results.size(); i++) {
        arr[results[i][0]][results[i][1]] = 1; // �̱�� 
        arr[results[i][1]][results[i][0]] = -1; // ����
    }
    
    for (int i = 1; i <= n; i++) { //���� ��� 
        for (int j = 1; j <= n; j++) { //�߰� ���
            for (int k = 1; k <= n; k++) { //�� ���
                if (arr[i][j] == 1 && arr[j][k] == 1) {// i�� j�� �̱�� j�� k�� �̱�� i�� k�� �̱����
                    arr[i][k] = 1;
                    arr[k][i] = -1;
                }
                else if (arr[i][j] == -1 && arr[j][k] == -1) { //i�� j���� ���� j�� k���� ������ i�� k���� ������
                    arr[k][i] = 1;
                    arr[i][k] = -1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) { //�� ���� ������ �ֵ��� �� Ȯ���ϸ� �� ������ �� �� ����
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0) cnt++;
        }
        if (cnt == n - 1) answer++;
    }

    return answer;
}

int main(void) {
    solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });
}