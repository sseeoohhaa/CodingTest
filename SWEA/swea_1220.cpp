/*
<230517>
SW Expert Academy 1220. [S/W 문제해결 기본] 5일차 - Magnetic
*/
#include <iostream>
using namespace std;

// 1 = N극 성질 자성체 = S극(하단)에 끌린다(go down) = 붉은 자성체
// 2 = S극 성질 자성체 = N극(상단)에 끌린다(go up) = 푸른 자성체
int main(int argc, char** argv) {
	
    int tc, deadlock, con;
    int table[100][100];
    int i, j, k, m;
    for(tc = 1; tc <= 10; tc++) {
    	deadlock = 0;
        cin >> con; // 100
        for(i = 0; i < con; i++) {
            for(j = 0; j < con; j++) {
                cin >> m;
                table[i][j] = m;
            }
        }
        
        for(i = 0; i < con; i++) {
            for(j = 0; j < con; j++) {
                if(table[j][i] == 1 && table[j+1][i] == 2) {
                    deadlock++;
                }
            	else if(table[j][i] == 1 && table[j+1][i] == 1) {
                	table[j+1][i] = 1;
                    table[j][i] = 1;
                }
            	else if(table[j][i] == 1 && table[j+1][i] == 0) {
                	table[j+1][i] = 1;
                    table[j][i] = 0;
                }
            }
        }
        
        cout << "#" << tc << " " << deadlock << "\n";
    }  
    return 0;
}