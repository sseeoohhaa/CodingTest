#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string gear1, gear2;
    int i, j, min_len; // lmin_len menas answer
    bool flag; // flag about success kickdown
    cin >> gear1 >> gear2;
    
    min_len = gear1.length() + gear2.length();
    if(gear1.length() > gear2.length()) {
        swap(gear1, gear2); // gear1: short one
    }
    
    // start with gear1 right side - gear2 left side
    for(i = 0; i < gear1.length(); i++) {
        flag = false; // reset
        for(j = 0; j <= i; j++) { // gear1이 들어온 부분(i)만 2 - 2 확인
            if(gear2[j] == '2' && gear1[gear1.length() -1 -i + j] == '2') {
                flag = true; // 2 - 2
                break;
            }
        }
        if(flag == false) {
            min_len = min(min_len, (int)gear1.length() + (int)gear2.length() - i -1); 
        }
    }
    
    // start with gear1 left side - gear2 right side
    for(i = 0; i < gear1.length(); i++) {
        flag = false; // reset
        for(j = 0; j <= i; j++) {
            if(gear2[gear2.length() -1 -i +j] == '2' && gear1[j] == '2') {
                flag = true; // 2 - 2
                break;
            }
        }
        if(flag == false) {
            min_len = min(min_len, (int)gear1.length() + (int)gear2.length() -i -1);
        }
    }
    
    // start with gear1 - gear2
    for(i = 0; i < gear2.length() - gear1.length(); i++) { // 두 기어가 범위를 벗어나지 않고 완전히 맞물리는 경우만
        flag = false; // reset
        for(j = 0; j < gear1.length(); j++) {
            if(gear1[j] == '2' && gear2[i+j] == '2') {
                flag = true;
                break;
            }
        }
        if(flag == false) {
            min_len = min(min_len, (int)gear2.length());
        }
    }

    cout << min_len;
    return 0;
}