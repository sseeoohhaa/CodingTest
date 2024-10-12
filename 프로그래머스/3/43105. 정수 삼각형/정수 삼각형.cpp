#include <string>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int height, m, n;
int sum[500][500]; // 각 위치까지의 합을 담을 배열

int solution(vector<vector<int>> triangle) {
    height = triangle.size();
    sum[0][0] = triangle[0][0]; // 초기값 세팅
    
    for(m = 1; m < height; m++) {
        for(n = 0; n <= m; n++) {
            if(n == 0) { // case 1. 맨 왼쪽 끝에 있는 숫자
                sum[m][n] = sum[m-1][0] + triangle[m][n];
            } else if(n == m) { // case 2. 맨 오른쪽 끝에 있는 숫자
                sum[m][n] = sum[m-1][n-1] + triangle[m][n];
            } else { // case 3. 가운데에 있는 숫자들
                sum[m][n] = max(sum[m-1][n-1], sum[m-1][n]) + triangle[m][n];
            }
    
            answer = max(answer, sum[m][n]);
        }
    }
    
    /* 최댓값 찾는 과정
    for(k = 0; k < height; k++) {
        answer = max(answer, sum[height-1][k]);
    } */
    
    return answer;
}