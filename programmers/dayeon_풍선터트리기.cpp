#include <string>
#include <vector>

using namespace std;
//��ȣ�� ���� ǳ���� ��Ʈ���� �� ���Ŀ��� �� ū ǳ���� ��Ʈ�� �� ����.

int solution(vector<int> a)
{
    int answer = 0;

    vector <int> start(a.size());
    vector <int> end(a.size());

    int min_val = a[0];

    for(int i = 0; i < a.size(); i++)
    {
        if(min_val > a[i])
            min_val = a[i];
        start[i] = min_val;
    }

    min_val = a[a.size() - 1];
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (min_val > a[i])
            min_val = a[i];
        end[i] = min_val;
    }

    for(int i = 0; i< a.size(); i++)
    {
        if(a[i] <= start[i] || a[i] <= end[i])
            answer++;
    }

    return answer;
}