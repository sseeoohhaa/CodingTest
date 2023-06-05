#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int i = 1;
    int sum, tmp;
    
    while(i <= n) {
        tmp = i;
        sum = 0;
        while(1) {
            sum+= tmp;
            if(sum == n) {
                answer++;
                break;
            } else if(sum > n) {
                break;
            }
            tmp++;
        }
        i++;
    } 
    
    return answer;
}