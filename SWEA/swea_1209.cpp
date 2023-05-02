/*
<230502>
SW Expert Academy 1209. [S/W 문제해결 기본] 2일차 - Sum
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
    
    int i, j, m, n, k;
    int test_case;
    int T  = 10;
    int arr[100][100];
    int sum[202]; // arr for sum
    
    for(test_case = 1; test_case <= T; test_case++) {
    	cin >> test_case;
        for(i = 0; i < 100; i++) {
            for(j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }
        
         fill(sum, sum + 202, 0); // reset
        
        for(m = 0; m < 100; m++) {
            for(n = 0; n < 100; n++) {
            	sum[m] += arr[m][n]; // sum of horizontal rows
                sum[m + 100] += arr[n][m]; // sum of vertical rows
            }
        }
        
        // diagonal sum
        for(k = 0; k < 100; k++ ) {
            sum[200] += arr[k][k];
            sum[201] += arr[k][100-k];
        }
                
        sort(sum, sum + 202); // ascending order sort(to find max value of sum)
    	cout << "#" << test_case << " " << sum[201] << "\n";
    } 
	return 0;
}