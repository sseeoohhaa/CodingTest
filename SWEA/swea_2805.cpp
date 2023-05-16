/*
<230516>
SW Expert Academy 2805. 농작물 수확하기
*/

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc, T; cin >> T;
    int arr[49][49];
    int i, j;
    for(tc = 1; tc <= T; tc++) {
    	int N, W, sum; cin >> N;
        string n;
        for(i = 0; i < N; i++) {
            cin >> n;
            for(j = 0; j < N; j++) {
                arr[i][j] = n[j] - '0';
            }
        }
        
        sum = 0;
        for(i = 0; i < N; i++) {
            if(i <= (N/2)) {
                for(j = (N/2) - i; j <= (N/2) + i; j++) {
                    sum += arr[i][j];
                }
            } else {
            	for(j = i - (N/2); j <= (N/2) + (N-i) - 1; j++) {
                    sum += arr[i][j];
                }
            }
        }
        
    	cout << "#" << tc << " " << sum << "\n";;
    }
    
    return 0;
}