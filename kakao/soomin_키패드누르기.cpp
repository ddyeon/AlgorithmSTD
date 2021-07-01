//
//  soomin_키패드누르기.cpp
//  
//
//  Created by 김수민 on 2021/07/01.
//

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left=10,right=11;
    
    int two[12]={3,1,0,1,2,1,2,3,2,3,4,4};
    int five[12]={2,2,1,2,1,0,1,2,1,2,3,3};
    int eight[12]={1,3,2,3,2,1,2,1,0,1,2,2};
    int zero[12]={0,4,3,4,3,2,3,2,1,2,1,1};
    for (int i=0; i<numbers.size();i++){
        int distance_l,distance_r;
        if ((numbers[i]==1)or(numbers[i]==4)or(numbers[i]==7)){
            answer+="L";
            left = numbers[i];
        }
        else if ((numbers[i]==3)or(numbers[i]==6)or(numbers[i]==9)){
            answer+="R";
            right = numbers[i];
        }
        else{
           if (numbers[i]==2){
                distance_l = two[left];
                distance_r = two[right];
            }
            else if (numbers[i]==5){
                distance_l=five[left];
                distance_r=five[right];
            }
            
             else if (numbers[i]==8){
                distance_l=eight[left];
                distance_r=eight[right];
            }
           
            else if (numbers[i]==0){
                distance_l=zero[left];
                distance_r=zero[right];
            }
            
            if (distance_l>distance_r){
                answer+="R";
                right=numbers[i];
                
            }
            
            else if (distance_r>distance_l){
                answer+="L";
                left=numbers[i];
            }
            else if (distance_r==distance_l){
                if (hand[0]=='r'){
                    answer+="R";
                    right=numbers[i];
                }
                else{
                    answer+="L";
                    left=numbers[i];
                }
            }
            
        }
    }
    return answer;
}
