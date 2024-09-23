#include <string>
#include <iostream>
using namespace std;

int rem = 0; // 2진수 변환 과정에서 나머지를 담을 변수
int a, b, count = 0; // a와 b는 2진수로 변환했을 때 1의 갯수 의미

int binaryFunc(int c) {
    count = 0;
    while(1) {
        rem = c % 2;
        c = c / 2;
        if(rem == 1) {
            count++; // 1의 갯수 count
        }
        if(c < 2) break; // while문 종료
    }
    return count;
}

int solution(int n) {
    int answer = n;

    a = binaryFunc(n);
    
    // answer 찾는 과정
    while(1) {
        answer++;
        b = binaryFunc(answer);
        
        if(a == b) break; // 종료
    }
    
    return answer;
}