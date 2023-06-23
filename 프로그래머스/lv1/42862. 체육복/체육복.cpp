#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int i, j, lo;
    bool flag;
    
    // 여벌을 가지고 있고, 자기 자신이 도난당한 경우 제거
    for(i = 0; i < lost.size(); i++) {
        for(j = 0; j < reserve.size(); j++) {
            if(lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--; j--;
            }
        }
    }
    
    // 정렬([4, 2], [3, 5] 같은 케이스를 위해서)
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(i = 0; i < lost.size(); i++) {
        lo = lost[i];
        flag = false;
        for(j = 0; j < reserve.size(); j++) {
            if(flag == 0) {
            	if(reserve[j] == lost[i] - 1 or reserve[j] == lost[i] + 1) {
                    flag = true;
                    reserve.erase(remove(reserve.begin(), reserve.end(), reserve[j]), reserve.end());
                }
            }
        }
        if(flag == 0) {
            n--;
        }
    }
    
    answer = n;
    return answer;
}