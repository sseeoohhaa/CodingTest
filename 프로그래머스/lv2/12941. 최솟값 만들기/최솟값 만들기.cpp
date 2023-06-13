#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int i;
    int len = A.size();
    /*vector<int> comb;
    for(i = 0; i < len; i++) {
        comb.emplace_back(A[i]);
        comb.emplace_back(B[i]);
    }*/
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    for(i = 0; i < len; i++) {
        answer+=A[i]*B[i];
        /*answer+=(comb.front()*comb.back());
        comb.erase(comb.begin());
        comb.erase(comb.end() - 1);*/
        
    }
    
    return answer;
}