#include <iostream>
using namespace std;

//���̾�Ʈ�� �������� �۵�
//�����̵��� ������ ��뷮 �������� kĭ �����ϸ� k��ŭ ������ ��뷮 ��.
//�����ϴ���, x2�ϴ���(�����̵��� ������ ������)

int solution(int n)
{
    int ans = 0;

    while (n > 0)
    {
        if (n % 2 == 1) //�������� 1�Ǹ� �����ؾ���.
            ans++;
        n /= 2;
    }

    return ans;
}