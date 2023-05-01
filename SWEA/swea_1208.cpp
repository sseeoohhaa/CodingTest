/*
<230501>
SW Expert Academy 1208. [S/W 문제해결 기본] 1일차 - Flatten
*/

#include<iostream>
#include<vector>
#include <algorithm> // to find max, min value
using namespace std;

int main(int argc, char** argv) {
	int test_case;
    int dump;
    vector<int> v;
    int height[10]; // high point-low point height difference
    
	for(test_case = 0; test_case <= 10; test_case++) {
        cin >> dump;
        v.clear(); // 테스트 케이스가 바뀔 때마다 벡터 내용(기존 값) 삭제
        for(int i = 0; i < 100; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        
        for(int j = 0; j < dump; j++) {
            if(height[test_case] == 1) { // 평탄화가 완료됐을 시
            	break;
            }
            
            int high_index = max_element(v.begin(), v.end())-v.begin();
            int low_index = min_element(v.begin(), v.end()) - v.begin();
            
            v[high_index] -= 1;
            v[low_index] += 1;
            
            // 평탄화 후의 최고, 최저점을 다시 찾아주어야 함
             high_index = max_element(v.begin(), v.end())-v.begin();
             low_index = min_element(v.begin(), v.end()) - v.begin();
            
            height[test_case] = v[high_index] - v[low_index];
        }
	}
    
    for(test_case = 0; test_case < 10; test_case++) {
        cout << "#" << test_case+1 << " " << height[test_case] << "\n";
    }
    
	return 0;
}
