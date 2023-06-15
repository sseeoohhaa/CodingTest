#include <iostream>
using namespace std;

char board[50][50];
int visit[50][50];
int cnt = 0;
int i, j, N, M;

void dfs(int r, int c) {
    visit[r][c] = 1;
    if(board[r][c] == '-') {
        // for(k = c+1; k < M; k++) { }
        if(c + 1 < M) {
            if(board[r][c + 1] != board[r][c]) { // 이전 장식과 다를 때
                return;
            } else {
                if(!visit[r][c + 1]) {
                    dfs(r, c + 1);
                }
            }
        }
    } else {
        if(r + 1 < N) {
            if(board[r + 1][c] != board[r][c]) { // 이전 장식과 다를 때
                return;
            } else {
                if(!visit[r + 1][c]) {
                    dfs(r + 1, c);
                }
            }
        }
    }
    
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < M; j++) {
            if(visit[i][j]) {
                continue;
            }
            else {
                cnt++;
                dfs(i, j);
                
            }
        }
    }
    
    cout << cnt;
    return 0;
}