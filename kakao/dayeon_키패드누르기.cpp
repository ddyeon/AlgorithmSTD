#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//147�� �޼�, 369�� ������, 2580�� �޼հ� ������ �� ����� ��.
//[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
//"right" "LRLLLRLLRRL"
//�Ÿ��� ���ٸ� hand������
//�̵���ĭ�� �Ÿ��� 1

vector<pair<int, int>> leftNow; //���� ��ġ�� ������ ����
vector<pair<int, int>> rightNow;

void calDist(int num, string hand)
{
    int now_x = (num -1) / 3;
    int now_y = (num -1) % 3;

    if(hand == "left")
        leftNow.push_back({now_x, now_y});
    else
    {
        rightNow.push_back({now_x, now_y});
    }
    
    
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    for(int i = 0; i < numbers.size(); i++ )
    {
         leftNow.clear();
         rightNow.clear();
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer+='L';
            calDist(numbers[i], "left"); //������ǥ ����
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer+='R';
            calDist(numbers[i], "right");
        }
        else //2580�ΰ��
        {
        
            int cur_x = (numbers[i] - 1) / 3;
            int cur_y = (numbers[i] - 1) % 3;
        
          
          int left_dist = abs(leftNow.front().first - cur_x) + abs(leftNow.front().second - cur_y);
          int right_dist = abs(rightNow.front().first - cur_x) + abs(rightNow.front().second - cur_y);

          if(left_dist > right_dist)
              answer += 'R';
          else if(left_dist < right_dist)
              answer += 'L';
          else //�������
          {
              if(hand =="left")
              {
                  answer += 'L';
                  calDist(numbers[i], "left");
              }
                 
              else
              {
                  answer += 'R';
                  calDist(numbers[i], "right");
              }
                
               
          }
          
        }
        
    }

   
    return answer;
}
