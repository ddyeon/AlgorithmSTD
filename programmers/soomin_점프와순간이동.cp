//
//  main.cpp
//  soomin_점프와 순간이동
//
//  Created by 김수민 on 2021/07/22.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    vector <int> v;
    int ans = 0;
    
    while (n > 0){
        if (n % 2 == 0){ //순간이동
            n /= 2;
        }
        else{
            ans += 1;
            n -= 1;
        }
    }
  
    return ans;
}

int main(){
    cout << solution(5) << endl;
    cout << solution(5000);
}
