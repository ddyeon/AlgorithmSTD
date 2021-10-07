#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ax = 0;
    int bx = 0;

    while(bx < A.size())
    {
        if (A[ax] < B[bx])
        {
            answer++;
            ax +=1;
            bx +=1;
        }
        else
            bx +=1;
        
    }


    return answer;
}

int main()
{
    // [ 5, 1, 3, 7 ][2, 2, 6, 8] 3
    // [2, 2, 2, 2][1, 1, 1, 1] 0

}