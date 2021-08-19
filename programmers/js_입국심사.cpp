#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1;
    long long right = (long long)(*max_element(times.begin(), times.end())) * n;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        
        for (int i = 0; i < times.size(); i++)
            cnt += (long long) mid / times[i];

        if (cnt >= n)
            right = mid - 1;
        
        else
            left = mid + 1;
    }
  
    return left;
}

int main() {
    int n = 6;
    vector<int>times = { 7,10 };
    cout<<solution(n, times);
}