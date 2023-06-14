#include <iostream>
using namespace std;

void Print(char board[200][200], int R, int C) {
    for(int i = 0; i < R; i++) {
        for(int j =0; j < C; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int R, C, N, i, j, m, n, Time;
    char board[200][200]; // 격자판
    int bomb[200][200]; // 폭탄 위치를 표시할 배열
    
    cin >> R >> C >> N;
    for(i = 0; i < R; i++) {
        for(j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    for(i = 0; i < R; i++) {
        for(j = 0; j < C; j++) {
            if(board[i][j] == 'O') {
                bomb[i][j]++;
            }
        }
    }
    Time = 1; // 1초 지난 후
    
    while(1) {
        if(Time == N) {
            Print(board, R, C);
            break;
        }
        
        Time++; // 시간 증가를 먼저 해줌
        
        if(Time % 2 == 0) {
            for(i = 0; i < R; i++) {
                for(j = 0; j < C; j++) {
                    board[i][j] = 'O';
                }
            }
        } else {
            for(i = 0; i < R; i++) {
                for(j = 0; j < C; j++) {
                    if(bomb[i][j] == 1) {
                        board[i][j] = '.';
                        if(i > 0) {
                            board[i-1][j] = '.';
                        }
                        if(i < R - 1) {
                            board[i+1][j] = '.';
                        }
                        if(j < C - 1) {
                            board[i][j+1] = '.';
                        }
                        if(j > 0) {
                            board[i][j-1] = '.';
                        }
                    }
                }
            }
            // reset bomb arr(폭탄 위치 기록 초기화)
            for(m = 0; m < R; m++) {
                for(n = 0; n < C; n++) {
                    bomb[m][n] = 0;                   
                }   
            }
            for(m = 0; m < R; m++) {
                for(n = 0; n < C; n++) {
                    if(board[m][n] == 'O') {
                    bomb[m][n]++;
                    }
                }
            }
        }
    }
    
    return 0;
}