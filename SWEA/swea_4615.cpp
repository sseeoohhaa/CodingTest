/*
<230514>
SW Expert Academy 4615. 재미있는 오셀로 게임
*/

#include <iostream>
using namespace std;

int main(int argc, char ** argv) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, tc; cin >> T; // test case
    
    for(tc = 1; tc <= T; tc++) {
    int N, M; cin >> N; cin >> M;
    int board[N][N] {};
    board[N/2 - 1][N/2 - 1] = 2; board[N/2][N/2 - 1] = 1; board[N/2 - 1][N/2] = 1; board[N/2][N/2] = 2;
    int x, y, W = 0, B = 0;
    int turn; // W or B
        
    int d[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // e, w, s, n, se, sw. ne, nw
    
    while(M > 0) {
    	cin >> x; cin >> y; cin >> turn;
        board[y-1][x-1] = turn;
        int curY = y-1, curX = x-1;
        
        for(int i = 0; i < 8; i++) { // search in 8 directions(동, 서, 남, 북, 대각선 네 방향)
        	int nextY = curY + d[i][0]; // move row
            int nextX = curX + d[i][1]; // move col
            int k = 1;
            while(true) {
                if((board[nextY][nextX] == 0) or (nextY < 0) or (nextX < 0) or (nextY == N) or (nextX == N)) { // over the space
                    break;
                }
                if(board[nextY][nextX] == turn && k == 1) { // when there is an opposing stone(case: W B or W B B...)
                    break;
                }
                if(board[nextY][nextX] == turn && k > 1) { // case: W B W or W B B...W
                    int nextY_ = curY + d[i][0]; // to move row and change W - B
                    int nextX_ = curX + d[i][1]; // to move col and change W - B
                    for(int j = 0; j < k; j++) {
                        board[nextY_][nextX_] = turn;
                        nextY_ += d[i][0];
                        nextX_ += d[i][1];
                    }
                    break;
                }
                nextY+= d[i][0];
                nextX+= d[i][1];
                k++;
           } // while
        } // for
        
        M--;
    } // while
    
    // Count W & B
    for (int m = 0; m < N; m++) {
        for (int n = 0; n < N; n++) {
            if (board[m][n] == 1) {
                B++;
            } else if(board[m][n] == 2) {
                W++;
            }
        }
    }
        
    cout << "#" << tc << " " << B << " " << W << "\n";
    }
    return 0;
}