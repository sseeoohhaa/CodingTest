/*
<230503>
SW Expert Academy 1215. [S/W 문제해결 기본] 3일차 - 회문1
*?

#include <iostream>
#include <string>
#include <algorithm> // to use string reverse
using namespace std;

int T = 10, tc, len, palindrome, i, j, k; // tc means test case
char word[8][8];
string str, str_original;

int Calculate() {
	cin >> len;
    for(i = 0; i < 8; i++) {
    	for(j = 0; j < 8; j++) {
        	cin >> word[i][j];
        }
    }
    palindrome = 0; // reset palindrome
    
    // horizontal palindrome check
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++){
            str.clear();
            for(k = 0; k < len; k++) {
                if(j+len >= 9) { // If it go beyond 8 squares
                    break;
                }
                str += word[i][j+k];
            }
            str_original = str; // original str
            reverse(str.begin(), str.end()); // reverse
            if((str_original.compare(str) == 0) && (!str.empty())) {
                palindrome += 1;
            }
        }
    }
    
    // vertical palindrome check
    for(i = 0; i < 8; i++) {
    	for(j = 0; j < 8; j++) {
            str.clear();
        	for(k = 0; k < len; k++) {
                if(i+len >= 9) { // If it go beyond 8 squares
                    break;
                }
                str += word[i+k][j];
            }
           str_original = str;
           reverse(str.begin(), str.end());
           if((str_original.compare(str) == 0) && (str.length() != 0)) {
               palindrome += 1;
            }
        }
    }
    return palindrome;   
}

int main(int argc, char **argv) {
    for(tc = 1; tc <= T; tc++) {
    	cout << "#" << tc << " " << Calculate() <<"\n";
    }
	return 0;
}
